/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

int quest_enable(game_t *game, size_t id)
{
    sfTime now;

    if (!game || id >= game->sysquest.size) {
        return EXIT_ERROR;
    } else if (game->sysquest.is_enable[id] == true) {
        return EXIT_FAILURE;
    }
    game->sysquest.is_enable[id] = true;
    game->sysquest.size_enable += 1;
    now = sfClock_getElapsedTime(game->clock);
    game->sysquest.time_begin[id] = now.microseconds;
    if (game->sysquest.pnj_dialogue != NULL) {
        dialogue_enable(&game->sysquest, id);
    }
    return EXIT_SUCCESS;
}
