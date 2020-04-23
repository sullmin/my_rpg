/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_world
*/

#include "my_rpg.h"

void event_main_world(game_t *game, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        game->state = PAUSE_MENU;
        return;
    }
    event_player(game, event);
}