/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_slider
*/

#include "my_rpg.h"

void set_slider_color(slider_t *slider, sfColor bar, sfColor button)
{
    sfRectangleShape_setFillColor(slider->rect, bar);
    sfCircleShape_setFillColor(slider->circle, button);
}

void set_slider_position(slider_t *slider, float percent)
{
    float length = slider->rect_size.x;
    float shift_pos = length * (percent / 100);

    slider->circle_pos.x = slider->rect_pos.x;
    slider->circle_pos.x += (shift_pos - slider->circle_radius);
    update_slider_position(slider);
}

void update_slider_position(slider_t *slider)
{
    sfRectangleShape_setPosition(slider->rect, slider->rect_pos);
    sfCircleShape_setPosition(slider->circle, slider->circle_pos);
}

void set_slider_size(slider_t *slider)
{
    sfRectangleShape_setSize(slider->rect, slider->rect_size);
    sfCircleShape_setRadius(slider->circle, slider->circle_radius);
}
