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
        game->state = QUIT;
    if (game->pause->resume->toggle == 2)
        game->state = MAIN_WORLD;
    if (game->pause->main_menu->toggle == 2)
        game->state = MAIN_MENU;
    event_button(game->pause->quit, game->w.window);
    event_button(game->pause->resume, game->w.window);
    event_button(game->pause->main_menu, game->w.window);
}
