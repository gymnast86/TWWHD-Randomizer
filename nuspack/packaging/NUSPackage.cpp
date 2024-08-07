#include "NUSPackage.hpp"

#include <filesystem>

#include <nuspack/packaging/ContentRulesService.hpp>
#include <nuspack/packaging/Cert.hpp>
#include <nuspack/contents/contents.hpp>
#include <nuspack/crypto/Encryption.hpp>
#include <utility/file.hpp>
#include <utility/math.hpp>
#include <libs/hashing.hpp>



static SHA1 sha1;
static SHA256 sha256;

void readFiles(const fspath& dir, FSTEntry& parent, const bool& notInNUS = false) {
    for(auto item : std::filesystem::directory_iterator(dir)) {
        if(std::filesystem::is_regular_file(item)) {
            FSTEntry& child = parent.children.emplace_back();
            child.entry.emplace<FSTEntry::FileEntry>(std::filesystem::file_size(item));

            child.path = item.path();
            child.parent = &parent;
            child.name = child.path.filename().string();
        }
    }
    for(auto item : std::filesystem::directory_iterator(dir)) {
        if(std::filesystem::is_directory(item)) {
            FSTEntry& child = parent.children.emplace_back();
            child.entry.emplace<FSTEntry::DirEntry>();
            
            readFiles(item, parent.children.back(), notInNUS);
            child.path = item.path();
            child.parent = &parent;
            child.name = child.path.filename().string();
        }
    }
}

NUSPackage::NUSPackage(const PackageConfig& config) :
    ticket(config.info.titleID, config.encryptionKey, config.encryptKeyWith),
    contents(),
    fst(contents),
    tmd(ticket, contents),
    outputDir()
{
    fst.root.setContent(&contents.GetFSTContent());
    readFiles(config.dir, fst.root, false);
    applyRules(fst.root, contents, config.rules);

    fst.Update();
    tmd.update(config.info);
}

void NUSPackage::PackContents(const fspath& out) {
    Utility::create_directories(out);

    Encryption encryption = tmd.getEncryption();
    fst.contents.PackContents(out, encryption);

    const fspath fstPath = out / "00000000.app";
    std::stringstream fstStream;
    fst.writeToStream(fstStream);
    Utility::seek(fstStream, roundUp<size_t>(fstStream.tellp(), 0x8000), std::ios::beg);
    fstStream.seekg(0, std::ios::beg);
    std::ofstream fstFile(fstPath, std::ios::binary);
    encryption.EncryptFileWithPadding(fstStream, 0, fstFile, Content::PAD_LEN);

    Content& fstContent = fst.contents.GetFSTContent();
    std::string hash = sha1(fstStream.str());
    std::copy(hash.begin(), hash.begin() + 20, fstContent.hash.data());
    fstContent.size = roundUp<uint64_t>(fstStream.str().size(), 0x8000);

    std::stringstream contentsStream;
    fst.contents.writeToStream(contentsStream);
    std::string hash2 = sha256(contentsStream.str());
    std::copy(hash2.begin(), hash2.begin() + 0x20, tmd.contentInfo.hash.data());
    tmd.UpdateContentInfoHash();

    std::ofstream tmdOut(out / "title.tmd", std::ios::binary);
    tmd.writeToStream(tmdOut);

    std::ofstream certOut(out / "title.cert", std::ios::binary);
    writeCertData(certOut);

    std::ofstream tikOut(out / "title.tik", std::ios::binary);
    ticket.writeToStream(tikOut);
}
