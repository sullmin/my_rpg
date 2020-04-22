/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_world
*/

#include "my_rpg.h"

static void event_move(game_t *game, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(game->option->move->forward)
        && game->wmain->rect->top - 16 > 0) {
        game->wmain->rect->top -= 16;
        sfSprite_setTextureRect(game->wmain->sprite, *game->wmain->rect);
    }
    if (sfKeyboard_isKeyPressed(game->option->move->backward)
        && game->wmain->rect->top + 16 <= 1232) {
        game->wmain->rect->top += 16;
        sfSprite_setTextureRect(game->wmain->sprite, *game->wmain->rect);
    }
    if (sfKeyboard_isKeyPressed(game->option->move->right)
        && game->wmain->rect->left + 16 <= 992) {
        game->wmain->rect->left += 16;
        sfSprite_setTextureRect(game->wmain->sprite, *game->wmain->rect);
    }
    if (sfKeyboard_isKeyPressed(game->option->move->left)
        && game->wmain->rect->left - 16 > 0) {
        game->wmain->rect->left -= 16;
        sfSprite_setTextureRect(game->wmain->sprite, *game->wmain->rect);
    }
}

void event_main_world(game_t *game, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        game->state = PAUSE_MENU;
        return;
    }
    event_move(game, event);
}