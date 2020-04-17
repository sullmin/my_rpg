/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-17T17:51:02+02:00 | Author: simon
*/

#include "my_rpg.h"

// Teleportation point (coord where the player change => scene)

static const sfVector2i TP_COORD[2] =
{
    {10, 25},
    {11, 25}
};

static const size_t TP_COORD_SIZE = 2;

static const sfVector2i POST_TP_COORD = {16, 26};

static void tp_player(game_t *game)
{
    object_on_map_set_coord(&ISOW.player, &ISOW.map,
    POST_TP_COORD.x, POST_TP_COORD.y);
    game->state = MAIN_WORLD;
}

void check_tp_point(game_t *game)
{
    for (size_t i = 0; i < TP_COORD_SIZE; i++) {
        if (ISOW.player.coord_map.x == TP_COORD[i].x
            && ISOW.player.coord_map.y == TP_COORD[i].y) {
            tp_player(game);
        }
    }
}
