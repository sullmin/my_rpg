/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_box_on_pos
*/

#include "my_rpg.h"

bool check_box_on_pos(game_t *game, sfVector2i *pos_array, size_t nb_box)
{
    for (size_t i = 0; i < nb_box; i++) {
        if (WMAIN->hitbox[pos_array[i].y][pos_array[i].x] != 'B') {
            return false;
        }
    }
    return true;
}