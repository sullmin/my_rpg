/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_option_menu
*/

#include "my_rpg.h"

void destroy_option_menu(game_t *game)
{
    sfTexture_destroy(MENU_OPTION->txr_background);
    sfSprite_destroy(MENU_OPTION->spr_background);
    destroy_button(game->option_menu->azerty);
    destroy_button(game->option_menu->qwerty);
    destroy_button(game->option_menu->keypad);
    destroy_button(game->option_menu->main_menu);
    destroy_button(game->option_menu->chara1);
    destroy_button(game->option_menu->chara2);
    destroy_slider(game->option_menu->sound);
    free(game->option_menu);
}
