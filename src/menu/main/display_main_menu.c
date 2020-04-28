/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_main_menu
*/

#include "my_rpg.h"

void display_main_menu(game_t *game)
{
    sfRenderWindow_drawSprite(WINDOW, MMENU->spr_background, NULL);
    display_button(MMENU->play, game->w.window);
    display_button(MMENU->quit, game->w.window);
    display_button(MMENU->option, game->w.window);
    display_button(MMENU->help, game->w.window);
}
