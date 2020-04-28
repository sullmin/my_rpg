/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_menu
*/

#include "my_rpg.h"

void event_main_menu(game_t *game, sfEvent *event)
{
    (void)event;
    if (MMENU->quit->toggle == 2)
        set_game_state(game, QUIT);
    if (MMENU->help->toggle == 2)
        set_game_state(game, HELP_MENU);
    if (game->menu->play->toggle == 2) {
        if (game->prev_state == QUIT) {
            set_game_state(game, ISO_WORLD);
        } else {
            set_game_state(game, game->prev_state);
        }
    }
    if (MMENU->option->toggle == 2)
        set_game_state(game, OPTION_MENU);
    event_button(MMENU->option, game->w.window);
    event_button(MMENU->play, game->w.window);
    event_button(MMENU->quit, game->w.window);
    event_button(MMENU->help, game->w.window);
}
