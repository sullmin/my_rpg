/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_pause_menu
*/

#include "my_rpg.h"

void destroy_pause_menu(game_t *game)
{
    destroy_button(game->pause->quit);
    destroy_button(game->pause->resume);
    destroy_button(game->pause->main_menu);
    sfSprite_destroy(game->pause->spr_screen);
    sfTexture_destroy(game->pause->txr_screen);
    free(game->pause);
}