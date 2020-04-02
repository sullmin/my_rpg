/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

extern const quest_t QUEST_ARRAY[];

static void quest_give_reward(game_t *game, size_t id)
{

}

int quest_finish(sys_quest_t *quests, game_t *game, size_t id)
{
    sfInt64 now = sfClock_getElapsedTime(game->clock).microseconds;

    if (!quests)
        return EXIT_ERROR;
    quests->size_enable -= 1;
    quests->is_active[id] = false;
    if ((now - quests->time_begin[id]) > QUEST_ARRAY[id].max_duration) {
        dialogue_play(quests, IDX_DIALOGUE_FAIL);
    } else {
        dialogue_play(quests, IDX_DIALOGUE_END);
        quest_give_reward(game, id);
    }
    return EXIT_SUCCESS;
}
