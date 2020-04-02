/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_slider
*/

#include "my_rpg.h"

void display_slider(slider_t *slider, sfRenderWindow *window)
{
    if (slider->rect)
        sfRenderWindow_drawRectangleShape(window, slider->rect, NULL);
    if (slider->circle) {
        sfCircleShape_setPosition(slider->circle,
        (sfVector2f){slider->circle_pos.x, slider->circle_pos.y});
        sfRenderWindow_drawCircleShape(window, slider->circle, NULL);
    }
}
