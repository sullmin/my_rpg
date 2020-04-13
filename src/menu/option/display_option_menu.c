/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_option_menu
*/

#include "my_rpg.h"

void display_option_menu(game_t *game)
{
    display_button(game->option_menu->azerty, game->w.window);
    display_button(game->option_menu->qwerty, game->w.window);
    display_button(game->option_menu->keypad, game->w.window);
    display_button(game->option_menu->main_menu, game->w.window);
    display_slider(game->option_menu->sound, game->w.window);
}