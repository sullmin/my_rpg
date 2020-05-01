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
    } else if (game->sysquest.is_active[id] == true) {
        return EXIT_FAILURE;
    }
    game->sysquest.is_active[id] = true;
    game->sysquest.size_enable += 1;
    now = sfClock_getElapsedTime(game->clock);
    game->sysquest.time_begin[id] = now.microseconds;
    dialogue_play(&game->sysquest, (int)id);
    menu_quest_reload(game);
    return EXIT_SUCCESS;
}
