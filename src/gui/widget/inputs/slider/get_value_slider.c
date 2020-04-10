/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_value_slider
*/

#include "my_rpg.h"

float get_value_slider(slider_t *slider)
{
    float position = slider->circle_pos.x - slider->min;
    float length = slider->max - slider->min;

    return (position / length);
}
