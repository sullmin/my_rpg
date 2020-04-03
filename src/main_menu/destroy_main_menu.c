/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_main_menu
*/

#include "my_rpg.h"

void destroy_main_menu(game_t *game)
{
    destroy_button(game->menu->option);
    destroy_button(game->menu->play);
    destroy_button(game->menu->quit);
    free(game->menu);
}