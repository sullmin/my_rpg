/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu
*/

#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

int create_pause_menu(game_t *game);
void destroy_pause_menu(game_t *game);
void display_pause_menu(game_t *game);
void event_pause_menu(game_t *game, sfEvent *event);

#endif /* !PAUSE_MENU_H_ */
