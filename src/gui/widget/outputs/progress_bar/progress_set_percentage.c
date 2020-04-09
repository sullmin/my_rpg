/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-09T18:21:45+02:00 | Author: simon
*/

#include "my_rpg.h"

int progress_set_percentage(progress_t *progress, unsigned int percent)
{
    sfVector2f size = {0, progress->size.y};

    if (!progress || percent > 100) {
        return EXIT_ERROR;
    }
    progress->percentage = percent;
    size.x = (double)progress->size.x * (((double)percent / 100.0f));
    sfRectangleShape_setSize(progress->rect_front, size);
    return EXIT_SUCCESS;
}
