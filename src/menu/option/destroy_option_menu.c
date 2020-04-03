/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_option_menu
*/

#include "my_rpg.h"

void destroy_option_menu(game_t *game)
{
    destroy_button(game->option_menu->azerty);
    destroy_button(game->option_menu->qwerty);
    destroy_button(game->option_menu->keypad);
    destroy_button(game->option_menu->main_menu);
    free(game->option_menu);
}