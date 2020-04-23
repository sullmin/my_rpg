/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_player
*/

#include "my_rpg.h"

static void compute_move_f(game_t *game)
{
    if (WMAIN->hitbox[WMAIN->position_on_map.y - 1][WMAIN->position_on_map.x]
        == '.') {
        WMAIN->position_on_map.y -= 1;
        if (WMAIN->rect->top - 16 > 0) {
            WMAIN->rect->top -= 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.y -= 16 * 4;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
    }
}

static void compute_move_b(game_t *game)
{
    if (WMAIN->hitbox[WMAIN->position_on_map.y + 1][WMAIN->position_on_map.x]
        == '.') {
        WMAIN->position_on_map.y += 1;
        if (WMAIN->rect->top + 16 <= 1232) {
        WMAIN->rect->top += 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.y += 16 * 4;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
    }
}

static void compute_move_r(game_t *game)
{
    if (WMAIN->hitbox[WMAIN->position_on_map.y][WMAIN->position_on_map.x + 1]
        == '.') {
        WMAIN->position_on_map.x += 1;
        if (WMAIN->rect->left + 16 <= 992) {
            WMAIN->rect->left += 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.x += 16 * 4;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
    }
}

static void compute_move_l(game_t *game)
{
    if (WMAIN->hitbox[WMAIN->position_on_map.y][WMAIN->position_on_map.x - 1]
        == '.') {
        WMAIN->position_on_map.x -= 1;
        if (WMAIN->rect->left - 16 > 0) {
            WMAIN->rect->left -= 16;
            sfSprite_setTextureRect(WMAIN->sprite, *WMAIN->rect);
        } else {
            WMAIN->position_player.x -= 16 * 4;
            sfSprite_setPosition(WMAIN->s_player, WMAIN->position_player);
        }
    }
}

void event_player(game_t *game, sfEvent *event)
{
    if (is_key_released(event, game->option->move->forward)
        && WMAIN->position_on_map.y - 1 >= 0) {
        compute_move_f(game);
    }
    if (is_key_released(event, game->option->move->backward)
        && WMAIN->position_on_map.y + 1 <= 92) {
        compute_move_b(game);
    }
    if (is_key_released(event, game->option->move->right)
        && WMAIN->position_on_map.x + 1 <= 91) {
        compute_move_r(game);
    }
    if (is_key_released(event, game->option->move->left)
        && WMAIN->position_on_map.x - 1 >= 0) {
        compute_move_l(game);
    }
}