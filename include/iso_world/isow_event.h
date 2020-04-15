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

void event_mouse_button_pressed(isow_t *isow, sfEvent *event);
void event_mouse_button_released(isow_t *isow, sfEvent *event);
void event_mouse_wheel_scroll(isow_t *isow, sfEvent *event);
void event_mouse_wheel_click(isow_t *isow, sfEvent *event);
void event_mouse_move(isow_t *isow, sfEvent *event);

void event_keypressed(isow_t *isow, sfEvent *event);

void event_object_move(isow_t *isow, sfEvent *event);

#endif
