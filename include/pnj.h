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
void collision_act(game_t *game);
bool collision_for_player(sfVector2i *player, game_t *game);
void pnj_evol(pnj_t *pnj, game_t *game, bool stat);
void player_move(game_t *game);

// PNJ ACTIONS

void vladimir_action(game_t *game, const size_t id_pnj);
void guardian_action(game_t *game, const size_t id_pnj);
void boss_action(game_t *game, const size_t id_pnj);
void random_alpha_action(game_t *game, const size_t id_pnj);

#endif
