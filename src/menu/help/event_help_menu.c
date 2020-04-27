/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_help_menu
*/

#include "my_rpg.h"

void event_help_menu(game_t *game, sfEvent *event)
{
    (void)event;
    if (MENU_HELP->main_menu->toggle == 2)
        set_game_state(game, MAIN_MENU);
    event_button(MENU_HELP->main_menu, game->w.window);
}