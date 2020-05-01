/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_box
*/

#include "my_rpg.h"

void dir_up(game_t *game, sfVector2i pos)
{
    if (WMAIN->hitbox[pos.y - 1][pos.x] == 'B' &&
        WMAIN->hitbox[pos.y - 2][pos.x] == '.') {
        WMAIN->hitbox[pos.y - 1][pos.x] = '.';
        WMAIN->hitbox[pos.y - 2][pos.x] = 'B';
        }
}

void dir_down(game_t *game, sfVector2i pos)
{
    if (WMAIN->hitbox[pos.y + 1][pos.x] == 'B' &&
        WMAIN->hitbox[pos.y + 2][pos.x] == '.') {
        WMAIN->hitbox[pos.y + 1][pos.x] = '.';
        WMAIN->hitbox[pos.y + 2][pos.x] = 'B';
    }
}

void dir_left(game_t *game, sfVector2i pos)
{
    if (WMAIN->hitbox[pos.y][pos.x - 1] == 'B' &&
        WMAIN->hitbox[pos.y][pos.x - 2] == '.') {
        WMAIN->hitbox[pos.y][pos.x - 1] = '.';
        WMAIN->hitbox[pos.y][pos.x - 2] = 'B';
    }
}

void dir_right(game_t *game, sfVector2i pos)
{
    if (WMAIN->hitbox[pos.y][pos.x + 1] == 'B' &&
        WMAIN->hitbox[pos.y][pos.x + 2] == '.') {
        WMAIN->hitbox[pos.y][pos.x + 1] = '.';
        WMAIN->hitbox[pos.y][pos.x + 2] = 'B';
    }
}
