/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_menu
*/

#ifndef OPTION_MENU_H_
#define OPTION_MENU_H_

#include "move_t.h"
#include "option_t.h"
#include "option_menu_t.h"

int create_option_menu(game_t *game);
void destroy_option_menu(game_t *game);
void display_option_menu(game_t *game);
void event_option_menu(game_t *game, sfEvent *event);

int set_keyboard_config(option_t *option, const int *keyconfig);

#endif /* !OPTION_MENU_H_ */
