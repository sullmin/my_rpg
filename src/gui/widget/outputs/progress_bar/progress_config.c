/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-09T18:21:45+02:00 | Author: simon
*/

#include "my_rpg.h"

int progress_set_color_front(progress_t *progress, sfColor color)
{
    if (!progress)
        return EXIT_ERROR;
    sfRectangleShape_setFillColor(progress->rect_front, color);
    return EXIT_SUCCESS;
}

int progress_set_color_back(progress_t *progress, sfColor color)
{
    if (!progress)
        return EXIT_ERROR;
    sfRectangleShape_setFillColor(progress->rect_back, color);
    return EXIT_SUCCESS;
}
