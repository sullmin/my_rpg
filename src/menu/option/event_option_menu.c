/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_option_menu
*/

#include "my_rpg.h"

void event_option_menu(game_t *game, sfEvent *event)
{
    event_button(game->option_menu->azerty, game->w.window);
    event_button(game->option_menu->qwerty, game->w.window);
    event_button(game->option_menu->keypad, game->w.window);
    event_button(game->option_menu->main_menu, game->w.window);
    if (game->option_menu->main_menu->toggle == 2)
        game->state = MAIN_MENU;
}