/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_pause_menu
*/

#include "my_rpg.h"

void display_pause_menu(game_t *game)
{
    display_button(game->pause->quit, game->w.window);
    display_button(game->pause->resume, game->w.window);
    display_button(game->pause->main_menu, game->w.window);
}