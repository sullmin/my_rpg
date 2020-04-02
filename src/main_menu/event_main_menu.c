/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_menu
*/

#include "my_rpg.h"

void event_main_menu(game_t *game, sfEvent *event)
{
    if (game->ui.main_menu->quit->toggle == 2)
        game->state = QUIT;
    if (game->ui.main_menu->play->toggle == 2)
        game->state = MAIN_WORLD;
    event_button(game->ui.main_menu->option, game->w.window);
    event_button(game->ui.main_menu->play, game->w.window);
    event_button(game->ui.main_menu->quit, game->w.window);
}