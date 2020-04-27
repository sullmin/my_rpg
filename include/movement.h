/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#ifndef MOVEM_H
#define MOVEM_H

#include "my_rpg.h"

#define TIME_MOVE 1

bool movement_creat(movement_t *mov, const char *sprite);
void destroy_movement(movement_t *mov);
void display_player(sfRenderWindow *window, movement_t *mov, bool act_move, float zoom);
void input_manage(game_t *game, sfEvent *event);
void built_it(movement_t *mov, size_t pos);

#endif