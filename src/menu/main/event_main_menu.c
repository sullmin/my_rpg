/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_main_menu
*/

#include "my_rpg.h"

void event_main_menu(game_t *game, sfEvent *event)
{
    if (game->menu->quit->toggle == 2)
        game->state = QUIT;
    if (game->menu->play->toggle == 2)
        game->state = MAIN_WORLD;
    if (game->menu->option->toggle == 2)
        game->state = OPTION_MENU;
    event_button(game->menu->option, game->w.window);
    event_button(game->menu->play, game->w.window);
    event_button(game->menu->quit, game->w.window);
}