/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_world
*/

#ifndef ISOW_H_
#define ISOW_H_

#define EXIT_ERROR 84

#define ISOW game->wiso
#define DEG_TO_RAD(x) ((x * M_PI) / 180)
#define RAD_TO_DEG(x) (int)(x * (180 / M_PI))
#define ABS(x) (x < 0) ? (-x) : (x)
#define V2F(x, y) (sfVector2f){x, y}
#define TIME_MILLI(clock) sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

#include "isow_t.h"
//#include "event_action.h"
#include "map.h"
#include "object.h"

// MAIN
int isow_create(isow_t *isow);
int isow_destroy(isow_t *isow);
int isow_event_manager(isow_t *isow);
int isow_run(game_t *game);

#endif
