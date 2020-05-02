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

//BOX
int display_box(game_t *game);
int move_box(game_t *game, enum direction dir);
void dir_up(game_t *game, sfVector2i pos);
void dir_down(game_t *game, sfVector2i pos);
void dir_left(game_t *game, sfVector2i pos);
void dir_right(game_t *game, sfVector2i pos);
bool check_box_on_pos(game_t *game, sfVector2i *pos_array, size_t nb_box);

void event_main_world(game_t *game, sfEvent *event);
void event_player(game_t *game, sfEvent *event);

int create_xp_bar(game_t *game);
int display_xp_bar(game_t *game);
int update_xp_bar(game_t *game);
void player_add_xp(game_t *game, int value);
void detect_stat_stage(game_t *game);

bool mw_camera_move(game_t *game, enum direction dir);

void update_map_position(game_t *game);
void update_position_on_map(game_t *game);
bool is_right_position(game_t *game, enum direction dir);

void player_teleportation(game_t *game);

void act_manage(game_t *game, const size_t id);

int player_display_hitbox_create(game_t *game);
void player_display_hitbox(game_t *game);

bool is_correct_door(sfVector2i *pos, game_t *game);

#endif /* !MAIN_WORLD_H_ */
