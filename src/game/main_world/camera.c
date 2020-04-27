/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-27T09:59:13+02:00 | Author: simon
*/

#include "my_rpg.h"

static bool vertical(game_t *game, enum direction dir)
{
    if (dir == UP) {
        update_map_position(game);
        return true;
    } else if (dir == DOWN) {
        update_map_position(game);
        return true;
    }
    return false;
}

static bool horizontal(game_t *game, enum direction dir)
{
    if (dir == LEFT) {
        update_map_position(game);
        return true;
    } else if (dir == RIGHT) {
        update_map_position(game);
        return true;
    }
    return false;
}

bool mw_camera_move(game_t *game, enum direction dir)
{
    if (vertical(game, dir)) {
        return true;
    } else if (horizontal(game, dir)) {
        return true;
    }
    return false;
}
