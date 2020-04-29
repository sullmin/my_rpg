/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound_t
*/

#ifndef SOUND_H_
#define SOUND_H_

#include "game_t.h"

void sound_effect_set_volume(game_t *game);
bool load_sound_effect(game_t *game);
void destroy_sound_effect(game_t *game);

#endif /* !SOUND_T_H_ */