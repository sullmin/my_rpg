/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_pause_menu
*/

#include "my_rpg.h"

void event_pause_menu(game_t *game, sfEvent *event)
{
    (void)event;
    if (game->pause->quit->toggle == 2)
        set_game_state(game, QUIT);
    if (game->pause->resume->toggle == 2) {
        set_game_state(game, game->prev_state);
    }
    if (game->pause->main_menu->toggle == 2)
        set_game_state(game, MAIN_MENU);
    event_button(game->pause->quit, game->w.window);
    event_button(game->pause->resume, game->w.window);
    event_button(game->pause->main_menu, game->w.window);
}
