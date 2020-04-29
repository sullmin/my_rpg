/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_rpg
*/

#ifndef PNJ_H_
#define PNJ_H_

#include "my_rpg.h"

#define PLAYER game->wmain->position_on_map

void simple_pnj_move(pnj_t *pnj, game_t *game);
bool init_all_pnj(pnj_manage_t *pnj_man, env_t *env);
void destroy_pnj(pnj_manage_t *pnj_man);
void display_all_pnj(game_t *game);

bool is_pnj_col(sfVector2i *player, sfVector2i *pnj);

#endif