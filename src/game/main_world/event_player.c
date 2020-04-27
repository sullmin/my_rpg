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
        if (WMAIN->rect->top - 16 > 0) {
            WMAIN->rect->top -= 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.y -= 16 * WMAIN->zoom;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
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
        if (WMAIN->rect->top + 16 <= 1232) {
        WMAIN->rect->top += 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.y += 16 * WMAIN->zoom;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
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
        if (WMAIN->rect->left + 16 <= 992) {
            WMAIN->rect->left += 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.x += 16 * WMAIN->zoom;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
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
        if (WMAIN->rect->left - 16 > 0) {
            WMAIN->rect->left -= 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.x -= 16 * WMAIN->zoom;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
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
