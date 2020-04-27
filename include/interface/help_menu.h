/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** help_menu
*/

#ifndef HELP_MENU_H_
#define HELP_MENU_H_

#include "help_menu_t.h"

int create_help_menu(game_t *game);
void destroy_help_menu(game_t *game);
void display_help_menu(game_t *game);
void event_help_menu(game_t *game, sfEvent *event);


#endif /* !HELP_MENU_H_ */
