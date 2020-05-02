/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-02T11:25:22+02:00 | Author: simon
*/

#include "my_rpg.h"

static bool are_greater_than(int *array, int stage, size_t size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += array[i];
    }
    if (sum < stage) {
        return false;
    }
    return true;
}

void detect_stat_stage(game_t *game)
{
    stat_t stat = get_player_stat(game);
    int stage[2] = {10, 20};
    int array[5] = {stat.agility, stat.strength, stat.speed, stat.resistance,
    stat.iq};

    if (!QUEST.is_active[7] && !QUEST.is_finish[7]
            && are_greater_than(array, stage[0], 5)) {
        quest_enable(game, 7);
    }
    if (QUEST.is_active[5] && are_greater_than(array, stage[1], 5)) {
        quest_finish(game, 5, true);
        quest_enable(game, 6);
    }
}
