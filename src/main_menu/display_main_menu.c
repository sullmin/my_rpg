/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_main_menu
*/

#include "my_rpg.h"

void display_main_menu(game_t *game)
{
    display_button(game->ui.main_menu->play, game->w.window);
    display_button(game->ui.main_menu->quit, game->w.window);
    display_button(game->ui.main_menu->option, game->w.window);
}