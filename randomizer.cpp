#include "tweaks.hpp"
#include "options.hpp"

RandoSession g_session{ "will be set up later", "will be set up later", "will be set up later" }; //declared outside of class for extern stuff

class Randomizer {
private:
	Settings settings;
	std::string seed;
	std::string permalink; //will likely be replaced with config struct later?
	std::string seedHash;
	std::string seedString;

	bool dryRun = false;
	bool noLogs = false;
	bool bulkTest = false;
	bool randomizeItems = true;

	//Logic logic; placeholder, might not be in a class like this

public:
	void randomize() {

		if (!dryRun) {
			init_tweaks(""); //replace with proper rpx path later
			apply_necessary_tweaks(settings.num_starting_triforce_shards, settings.starting_pohs, settings.starting_hcs);
			if (settings.instant_text_boxes) {
				make_all_text_instant();
			}
			if (settings.reveal_full_sea_chart) {
				Apply_Patch(RANDO_ROOT"/asm/patch_diffs/reveal_sea_chart_diff.json"); //replace with proper relative path
			}
			if (settings.add_shortcut_warps_between_dungeons) {
				add_cross_dungeon_warps();
			}
			if (settings.invert_sea_compass_x_axis) {
				Apply_Patch(RANDO_ROOT"/asm/patch_diffs/invert_sea_compass_x_axis_diff.json"); //replace with proper relative path
			}
			update_skip_rematch_bosses_game_variable(settings.skip_rematch_bosses);
			update_sword_mode_game_variable(settings.sword_mode);
			if (settings.sword_mode == SwordMode::NoSword) {
				Apply_Patch(RANDO_ROOT"/asm/patch_diffs/swordless_diff.json"); //replace with proper relative path
				Add_Relocations(RANDO_ROOT"/asm/patch_diffs/swordless_reloc.json"); //replace with proper relative path
				update_swordless_text();
			}
			update_starting_gear(settings.starting_gear);
			if (settings.remove_music) {
				Apply_Patch(RANDO_ROOT"/asm/patch_diffs/remove_music_diff.json"); //replace with proper relative path
			}
		}

		if (settings.randomize_charts) {
			//randomize charts
		}

		if (settings.randomize_starting_island) {
			//randomize_starting_island
		}

		if (settings.randomize_entrances != EntranceRando::None) {
			//randomize entrances
		}

		if (randomizeItems) {
			//randomize items
		}

		if (randomizeItems && !dryRun) {
			//save items
		}

		if (!dryRun) {
			//apply_necessary_post_randomization_tweaks(randomizeItems, logic.item_locations);
		}

		if (!dryRun) {
			//save everything
		}

		if (randomizeItems) {
			if (!settings.do_not_generate_spoiler_log) {
				//write SL
			}
			//write non-spoiler log
		}

		//done!
		return;
	}

};

