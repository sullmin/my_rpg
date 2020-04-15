/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_world
*/

#ifndef ISOW_H_
#define ISOW_H_

#define EXIT_ERROR 84

#define M_PI 3.1415926535
#define ISOW game->wiso
#define DEG_TO_RAD(x) ((x * M_PI) / 180)
#define RAD_TO_DEG(x) (int)(x * (180 / M_PI))
#define ABS(x) (x < 0) ? (-x) : (x)
#define V2F(x, y) (sfVector2f){x, y}
#define TIME_MILLI(clock) sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

#include "state_t.h"
#include "map_t.h"
#include "event_t.h"
#include "object_t.h"

#include "window.h"
#include "event_action.h"
#include "map.h"
#include "object.h"

// WINDOW
int window_create(window_t *w);
void window_destroy(window_t *w);
int window_run(window_t *w);
int window_reload(window_t *w);

void soft_state_init(state_t *state);

// MATH
bool point_is_on_triangle(sfVector2f a, sfVector2f b, sfVector2f c,
sfVector2f p);
bool point_is_on_circle(sfVector2i point, float radius, sfVector2f position);
float point_length(sfVector2f a, sfVector2f b);

// TOOLS FUNCTIONS
char *my_str_concat(const char *stra, const char *strb);
int schr_extension(char *str, const char *ext);
char **read_file(const char *filepath);

//Function qui s'incluent pas dans les autres fichiers merde putain
int create_leftbar(window_t *w);

#endif
