/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-27T16:33:56+02:00 | Author: simon
*/

#include "my_rpg.h"

static bool have_decimal(float nbr)
{
    nbr -= ((int)nbr);
    if (nbr == 0) {
        return false;
    }
    if (nbr < 0.3)
        return false;
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

static bool correct_move(sfVector2i *pos, game_t *game, size_t i)
{
    bool stat = false;

    if (WMAIN->hitbox[pos[i].y][pos[i].x] == '.') {
        stat = true;
    } else if (WMAIN->hitbox[pos[i].y][pos[i].x] == 'P' &&
        is_in_player_inv(&game->inventory, "113")) {
        stat = true;
        if (as_seconds(WMAIN->sound_effect[0].clock) > 2) {
            sfSound_play(WMAIN->sound_effect[0].sound);
            sfClock_restart(WMAIN->sound_effect[0].clock);
        }
    }
    return stat;
}

static void compute_futur_position(game_t *game, sfVector2f *futur_pos,
enum direction dir)
{
    if (dir == LEFT) {
        futur_pos->x -= WMAIN->shift_pos;
    } else if (dir == RIGHT)
        futur_pos->x += WMAIN->shift_pos;
    if (dir == UP) {
        futur_pos->y -= WMAIN->shift_pos;
    } else if (dir == DOWN)
        futur_pos->y += WMAIN->shift_pos;
}

bool is_right_position(game_t *game, enum direction dir)
{
    sfVector2f futur_pos = WMAIN->position_on_map;
    sfVector2i pos[4];
    size_t nb_test;

    compute_futur_position(game, &futur_pos, dir);
    nb_test = add_tests(futur_pos, pos);
    if (collision_for_player(&pos[0], game))
        return false;
    for (size_t i = 0; i < nb_test; i++) {
        if (!correct_move(pos, game, i)) {
            return false;
        }
    }
    return true;
}
