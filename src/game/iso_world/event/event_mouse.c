/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** event manager
*/

#include "isow.h"

void event_mouse_button_pressed(isow_t *isow, sfEvent *event)
{
    sfMouseButtonEvent evt = event->mouseButton;

    if (event->mouseButton.button == sfMouseMiddle) {

    } else if (event->mouseButton.button == sfMouseLeft) {

    }
}

void event_mouse_button_released(isow_t *isow, sfEvent *event)
{
    sfMouseButtonEvent evt = event->mouseButton;

    if (evt.button == sfMouseMiddle) {
    } else if (evt.button == sfMouseLeft) {
    }
}

void event_mouse_wheel_scroll(isow_t *isow, sfEvent *event)
{
    sfMouseWheelScrollEvent evt = event->mouseWheelScroll;

    map_scale(&isow->map, evt.delta);
    map_scale(&isow->map_water, evt.delta);
    object_set_size(&isow->player, isow->map.sampling.x, isow->map.sampling.y,
    isow->map.sampling.x * 2);
    object_set_size(&isow->prison, isow->map.sampling.x * 23,
    isow->map.sampling.y * 25, isow->map.sampling.x * 10);
}

void event_mouse_move(isow_t *isow, sfEvent *event)
{
    sfMouseMoveEvent evt = event->mouseMove;

    (void)evt;
}
