/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_slider
*/

#include "my_rpg.h"

int destroy_slider(slider_t *slider)
{
    sfRectangleShape_destroy(slider->rect);
    sfCircleShape_destroy(slider->circle);
    return EXIT_SUCCESS;
}