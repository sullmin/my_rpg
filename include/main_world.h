/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_world
*/

#ifndef MAIN_WORLD_H_
#define MAIN_WORLD_H_

#include "game_t.h"
#include "main_world_t.h"

int create_main_world(game_t *game);
void destroy_main_world(game_t *game);
void display_main_world(game_t *game);
void event_main_world(game_t *game, sfEvent *event);

#endif /* !MAIN_WORLD_H_ */
