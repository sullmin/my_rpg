/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_help_menu
*/

#include "my_rpg.h"

void display_help_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->w.window, MENU_HELP->spr_help, NULL);
    display_button(MENU_HELP->main_menu, game->w.window);
}