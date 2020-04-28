/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_main_menu
*/

#include "my_rpg.h"

void destroy_main_menu(game_t *game)
{
    sfTexture_destroy(MMENU->txr_background);
    sfSprite_destroy(MMENU->spr_background);
    destroy_button(MMENU->option);
    destroy_button(MMENU->play);
    destroy_button(MMENU->quit);
    destroy_button(MMENU->help);
    free(MMENU);
}
