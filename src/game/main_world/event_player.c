/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_player
*/

#include "my_rpg.h"

static void compute_move_forward(game_t *game)
{
    if (WMAIN->pos_on_map_int.y - WMAIN->shift_pos < 0) {
        return;
    }
    if (!is_right_position(game, UP)) {
        return;
    }
    WMAIN->position_on_map.y -= WMAIN->shift_pos;
    update_position_on_map(game);
    update_map_position(game);
}

static void compute_move_backward(game_t *game)
{
    if (WMAIN->position_on_map.y + WMAIN->shift_pos
        >= WMAIN->size_map.y) {
        return;
    }
    if (!is_right_position(game, DOWN)) {
        return;
    }
    WMAIN->position_on_map.y += WMAIN->shift_pos;
    update_position_on_map(game);
    update_map_position(game);
}

static void compute_move_right(game_t *game)
{
    if (WMAIN->position_on_map.x + 1 >= WMAIN->size_map.x)
        return;
    if (!is_right_position(game, RIGHT)) {
        return;
    }
    WMAIN->position_on_map.x += WMAIN->shift_pos;
    update_position_on_map(game);
    update_map_position(game);
}

static void compute_move_left(game_t *game)
{
    if (WMAIN->position_on_map.x - 1 < 0) {
        return;
    }
    if (!is_right_position(game, LEFT)) {
        return;
    }
    WMAIN->position_on_map.x -= WMAIN->shift_pos;
    update_position_on_map(game);
    update_map_position(game);
}

void event_player(game_t *game, sfEvent *event)
{
    WMAIN->timer += TIME_MILLI(WMAIN->clock);
    sfClock_restart(WMAIN->clock);
    if (WMAIN->timer >= WMAIN->ms_loop) {
        while (WMAIN->timer >= WMAIN->ms_loop) {
            WMAIN->timer -= WMAIN->ms_loop;
        }
        if (is_key_pressed(event, game->option->move->forward)) {
            compute_move_forward(game);
        }
        if (is_key_pressed(event, game->option->move->backward)) {
            compute_move_backward(game);
        }
        if (is_key_pressed(event, game->option->move->right)) {
            compute_move_right(game);
        }
        if (is_key_pressed(event, game->option->move->left)) {
            compute_move_left(game);
        }
    }
}
