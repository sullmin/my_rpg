/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_slider
*/

#include "my_rpg.h"

slider_t *create_slider(sfVector2f position, float length)
{
    slider_t *slider = malloc(sizeof(slider_t));

    if (slider == NULL)
        return NULL;
    slider->circle = sfCircleShape_create();
    slider->rect = sfRectangleShape_create();
    if (slider->circle == NULL || slider->rect == NULL)
        return NULL;
    slider->circle_pos = (sfVector2f){position.x, position.y - 10};
    slider->rect_pos = position;
    slider->rect_size = (sfVector2f){length, 8};
    slider->circle_radius = 15;
    slider->circle_pos.x += ((length / 2) - slider->circle_radius);
    slider->isPressed = sfFalse;
    slider->min = position.x;
    slider->max = slider->min + length - slider->circle_radius * 2;
    set_slider_position(slider);
    set_slider_size(slider);
    return slider;
}
