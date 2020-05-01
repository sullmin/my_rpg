/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-05-01T12:04:46+02:00 | Author: simon
*/

#include "my_rpg.h"

void player_add_xp(game_t *game, int value)
{
    WMAIN->xp += value;
    update_xp_bar(game);
}
