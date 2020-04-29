/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "my_rpg.h"

// EVENT

typedef void (* const EVENT_HANDLER)(isow_t *, sfEvent *, option_t *);
typedef sfEventType EVENT_TYPE;

void event_mouse_wheel_scroll(isow_t *isow, sfEvent *event, option_t *);

void event_keypressed(isow_t *isow, sfEvent *event, option_t *);
void event_keyreleased(isow_t *isow, sfEvent *event, option_t *);

void event_object_move(isow_t *isow, sfEvent *event, option_t *);

#endif
