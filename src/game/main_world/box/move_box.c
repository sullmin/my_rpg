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

int move_box(game_t *game, enum direction dir)
{
    sfVector2i pos = {0};

    pos.x = ceil(WMAIN->position_on_map.x) - 1;
    pos.y = ceil(WMAIN->position_on_map.y) - 1;
    if (dir == UP && pos.y - 2 >= 0)
        dir_up(game, pos);
    if (dir == DOWN && pos.y + 2 < WMAIN->size_map.y)
        dir_down(game, pos);
    if (dir == LEFT && pos.x - 2 >= 0)
        dir_left(game, pos);
    if (dir == RIGHT && pos.y + 2 < WMAIN->size_map.x)
        dir_right(game, pos);
    return EXIT_SUCCESS;
}
