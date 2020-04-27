/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_help_menu
*/

#include "my_rpg.h"

void destroy_help_menu(game_t *game)
{
    destroy_button(MENU_HELP->main_menu);
    sfSprite_destroy(MENU_HELP->spr_help);
    sfTexture_destroy(MENU_HELP->ter_help);
    free(MENU_HELP);
}