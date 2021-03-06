/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#ifndef MOVEM_H
#define MOVEM_H

#include "my_rpg.h"

bool movement_creat(chara_animation_t *mov, window_t window);
void destroy_movement(chara_animation_t *mov);
void display_player(game_t *game, chara_animation_t *mov, bool in_move);
void input_manage(game_t *game, sfEvent *event);
void built_it(chara_animation_t *mov, size_t pos);

int reload_player_sprite(game_t *game, size_t idx);

#endif
