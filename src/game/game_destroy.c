/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:31:51+01:00 | Author: simon
*/

#include "my_rpg.h"

void game_destroy(game_t *game)
{
    sound_manager_destroy(&game->sound);
}
