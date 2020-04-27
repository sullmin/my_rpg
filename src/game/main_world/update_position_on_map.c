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

static bool have_decimal(float nbr)
{
    nbr -= ((int)nbr);
    if (nbr == 0) {
        return false;
    }
    return true;
}

static size_t add_tests(sfVector2f futur_pos, sfVector2i *pos)
{
    size_t idx = 1;

    pos[0] = (sfVector2i){floor(futur_pos.x), floor(futur_pos.y)};
    if (have_decimal(futur_pos.x) && have_decimal(futur_pos.y)) {
        pos[idx++] = (sfVector2i){ceil(futur_pos.x), ceil(futur_pos.y)};
    }
    if (have_decimal(futur_pos.x)) {
        pos[idx++] = (sfVector2i){ceil(futur_pos.x), floor(futur_pos.y)};
    }
    if (have_decimal(futur_pos.y)) {
        pos[idx++] = (sfVector2i){floor(futur_pos.x), ceil(futur_pos.y)};
    }
    return idx;
}

bool is_right_position(game_t *game, enum direction dir)
{
    sfVector2f futur_pos = WMAIN->position_on_map;
    sfVector2i pos[4];
    size_t nb_test;

    if (dir == LEFT) {
        futur_pos.x -= WMAIN->shift_pos;
    } else if (dir == RIGHT)
        futur_pos.x += WMAIN->shift_pos;
    if (dir == UP) {
        futur_pos.y -= WMAIN->shift_pos;
    } else if (dir == DOWN)
        futur_pos.y += WMAIN->shift_pos;
    nb_test = add_tests(futur_pos, pos);
    for (size_t i = 0; i < nb_test; i++) {
        if (WMAIN->hitbox[pos[i].y][pos[i].x] != '.') {
            return false;
        }
    }
    return true;
}
