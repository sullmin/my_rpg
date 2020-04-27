/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_player
*/

#include "my_rpg.h"

static void compute_move_forward(game_t *game)
{
    if (WMAIN->position_on_map.y - 1 < 0) {
        return;
    }
    if (WMAIN->hitbox[WMAIN->position_on_map.y - 1][WMAIN->position_on_map.x]
        == '.') {
        WMAIN->position_on_map.y -= 1;
        mw_camera_move(game, UP);
    }
}

static void compute_move_backward(game_t *game)
{
    if (WMAIN->position_on_map.y + 1 >= WMAIN->size_map.y) {
        return;
    }
    if (WMAIN->hitbox[WMAIN->position_on_map.y + 1][WMAIN->position_on_map.x]
        == '.') {
        WMAIN->position_on_map.y += 1;
        mw_camera_move(game, DOWN);
    }
}

static void compute_move_right(game_t *game)
{
    if (WMAIN->position_on_map.x + 1 >= WMAIN->size_map.x) {
        return;
    }
    if (WMAIN->hitbox[WMAIN->position_on_map.y][WMAIN->position_on_map.x + 1]
        == '.') {
        WMAIN->position_on_map.x += 1;
        mw_camera_move(game, RIGHT);
    }
}

static void compute_move_left(game_t *game)
{
    if (WMAIN->position_on_map.x - 1 < 0) {
        return;
    }
    if (WMAIN->hitbox[WMAIN->position_on_map.y][WMAIN->position_on_map.x - 1]
        == '.') {
        WMAIN->position_on_map.x -= 1;
        mw_camera_move(game, LEFT);
    }
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
