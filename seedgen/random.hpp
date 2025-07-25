#pragma once

#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>
#include <array>
#include <random>

using Generator_t = std::mt19937_64;
using Seed_t = Generator_t::result_type;

Seed_t seedFromString(const std::string& str);
void Random_Init(Seed_t seed);
uint32_t Random(int min, int max);
double RandomDouble();
Generator_t& GetGenerator();

template <typename T>
T popRandomElement(std::vector<T>& vector)
{
    const auto idx = Random(0, vector.size());
    T selected = vector[idx];
    vector.erase(vector.begin() + idx);
    return selected;
}

template <typename Container>
auto& RandomElement(Container& container) {
    return container[Random(0, std::size(container))];
}
template <typename Container>
const auto& RandomElement(const Container& container) {
    return container[Random(0, std::size(container))];
}

//Shuffle items within a vector or array
template <typename T>
void shufflePool(std::vector<T>& vector) {
    for (std::size_t i = 0; i + 1 < vector.size(); i++)
    {
        std::swap(vector[i], vector[Random(i, vector.size())]);
    }
}
template <typename T, std::size_t size>
void shufflePool(std::array<T, size>& arr) {
    for (std::size_t i = 0; i + 1 < arr.size(); i++)
    {
        std::swap(arr[i], arr[Random(i, arr.size())]);
    }
}
