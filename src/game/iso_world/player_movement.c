/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-17T16:18:15+02:00 | Author: simon
*/

#include "isow.h"

int player_movement(isow_t *isow, game_t *game)
{
    if (isow->event.player_move == false) {
        return EXIT_SUCCESS;
    }
    if (isow->event.player_move_key_v == sfKeyUp)
        object_on_map_move(&isow->player, &isow->map, 0, -1);
    if (isow->event.player_move_key_v == sfKeyDown)
        object_on_map_move(&isow->player, &isow->map, 0, 1);
    if (isow->event.player_move_key_h == sfKeyLeft)
        object_on_map_move(&isow->player, &isow->map, -1, 0);
    if (isow->event.player_move_key_h == sfKeyRight)
        object_on_map_move(&isow->player, &isow->map, 1, 0);
    check_tp_point(game);
    camera_move(isow, &game->w);
    return EXIT_SUCCESS;
}
