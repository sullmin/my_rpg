/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_world
*/

#ifndef ISOW_H_
#define ISOW_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

#define EXIT_ERROR 84

#define ISOW game->wiso
#define DEG_TO_RAD(x) ((x * M_PI) / 180)
#define RAD_TO_DEG(x) (int)(x * (180 / M_PI))
#define ABS(x) (x < 0) ? (-x) : (x)
#define V2F(x, y) (sfVector2f){x, y}
#define TIME_MILLI(clock) sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

#include "isow_t.h"
#include "isow_map.h"
#include "isow_event.h"
#include "object.h"

// MAIN
int isow_create(game_t *game);
int isow_destroy(isow_t *isow);
void isow_event_manager(game_t *game, sfEvent *event);
void isow_run(game_t *game);

int player_movement(isow_t *isow, game_t *game);
void check_tp_point(game_t *game);
void camera_move(isow_t *isow, window_t *w);

// KINEMATIC

int kinem_create(isow_t *isow);
int kinem_destroy(isow_t *isow);

int kinem_start(isow_t *isow, sound_manager_t *sound);
int kinem_stop(isow_t *isow, sound_manager_t *sound);

int kinem_run(isow_t *isow, sound_manager_t *sound);

#endif
