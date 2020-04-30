/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_player
*/

#include "my_rpg.h"

static void compute_move(game_t *game, enum direction dir)
{
    if (!is_right_position(game, dir)) {
        return;
    }
    if (dir == LEFT)
        WMAIN->position_on_map.x -= WMAIN->shift_pos;
    else if (dir == RIGHT)
        WMAIN->position_on_map.x += WMAIN->shift_pos;
    if (dir == UP)
        WMAIN->position_on_map.y -= WMAIN->shift_pos;
    else if (dir == DOWN)
        WMAIN->position_on_map.y += WMAIN->shift_pos;
    update_position_on_map(game);
    update_map_position(game);
}

static void call_move_function(enum direction dir, game_t *game)
{
    if (dir == UP) {
        if (WMAIN->pos_on_map_int.y - WMAIN->shift_pos < 0)
            return;
        compute_move(game, UP);
    }
    if (dir == DOWN) {
        if (WMAIN->position_on_map.y + WMAIN->shift_pos >= WMAIN->size_map.y)
            return;
        compute_move(game, DOWN);
    }
    if (dir == RIGHT) {
        if (WMAIN->position_on_map.x + 1 >= WMAIN->size_map.x)
            return;
        compute_move(game, RIGHT);
    }
    if (dir == LEFT) {
        if (WMAIN->position_on_map.x - 1 < 0)
            return;
        compute_move(game, LEFT);
    }
}

void player_move(game_t *game)
{
    WMAIN->timer += TIME_MILLI(WMAIN->clock);
    sfClock_restart(WMAIN->clock);
    while (WMAIN->timer >= WMAIN->ms_loop) {
        WMAIN->timer -= WMAIN->ms_loop;
        if (WMAIN->is_player_move) {
            call_move_function(WMAIN->move_dir, game);
        }
    }
}
