/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_slider
*/

#include "my_rpg.h"

int event_slider(slider_t *slider, sfVector2i mouse)
{
    int shift = 0;

    if (point_is_on_circle(mouse, slider->circle_radius, slider->circle_pos))
        if (sfMouse_isButtonPressed(sfMouseLeft) && !slider->isPressed)
            slider->isPressed = sfTrue;
    if (slider->isPressed) {
        shift = mouse.x - (slider->circle_pos.x + slider->circle_radius);
        slider->circle_pos.x += shift;
        if (slider->circle_pos.x < slider->min)
            slider->circle_pos.x = slider->min;
        if (slider->circle_pos.x > slider->max)
            slider->circle_pos.x = slider->max;
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && slider->isPressed)
        slider->isPressed = sfFalse;
    return EXIT_SUCCESS;
}
