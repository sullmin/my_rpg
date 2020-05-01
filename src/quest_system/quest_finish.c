/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const quest_t QUEST_ARRAY[];

static void quest_give_reward(game_t *game, const size_t id)
{
    const quest_t CURR_QUEST = QUEST_ARRAY[id];

    if (CURR_QUEST.type_reward != REW_STAT) {
        if (!move_item_in_inventory(game, CURR_QUEST.reward_ref_item)) {
            puterr("ERR: Fail to add QUEST reward ITEM in INVENTORY\n", 0);
        }
    }
    WMAIN->xp += 5;
    sound_manager_play(&SOUND, SUCCESS);
}

int quest_finish(game_t *game, const size_t id, bool skip_dialogue)
{
    sfInt64 now = sfClock_getElapsedTime(game->clock).microseconds;

    if (!game)
        return EXIT_ERROR;
    my_printf("QUEST %lu : has been complete !\n", id);
    QUEST.size_enable -= 1;
    QUEST.is_active[id] = false;
    QUEST.is_finish[id] = true;
    if ((now - QUEST.time_begin[id]) > QUEST_ARRAY[id].max_duration
            && QUEST_ARRAY[id].max_duration != 0 && !skip_dialogue) {
        dialogue_play(&QUEST, IDX_DIALOGUE_FAIL);
    } else if (!skip_dialogue) {
        dialogue_play(&QUEST, IDX_DIALOGUE_END);
        quest_give_reward(game, id);
    }
    menu_quest_reload(game);
    return EXIT_SUCCESS;
}
