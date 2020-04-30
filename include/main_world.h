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

#define PLAYER_INT game->wmain->pos_on_map_int

int create_main_world(game_t *game);
void destroy_main_world(game_t *game);
void display_main_world(game_t *game);
int display_box(game_t *game);
void event_main_world(game_t *game, sfEvent *event);
void event_player(game_t *game, sfEvent *event);

int create_xp_bar(game_t *game);
int display_xp_bar(game_t *game);
int update_xp_bar(game_t *game);

bool mw_camera_move(game_t *game, enum direction dir);

void update_map_position(game_t *game);
void update_position_on_map(game_t *game);
bool is_right_position(game_t *game, enum direction dir);

#endif /* !MAIN_WORLD_H_ */
