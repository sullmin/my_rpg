/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-28T17:54:53+02:00 | Author: simon
*/

#include "my_rpg.h"

void credit_menu_event(game_t *game, sfEvent *event)
{
    if (is_key_pressed(event, sfKeyEscape) == true) {
        MENU_CREDIT.pos_front.y = -game->w.height;
        set_game_state(game, MAIN_MENU);
    }
}
