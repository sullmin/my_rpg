/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-27T16:33:56+02:00 | Author: simon
*/

#include "my_rpg.h"

void update_position_on_map(game_t *game)
{
    WMAIN->pos_on_map_int.x = floor(WMAIN->position_on_map.x);
    WMAIN->pos_on_map_int.y = floor(WMAIN->position_on_map.y);
}

void player_teleportation(game_t *game)
{
    WMAIN->position_on_map.y -= 2;
    update_position_on_map(game);
    update_map_position(game);
    sfClock_restart(ISOW.clock);
    set_game_state(game, ISO_WORLD);
}
