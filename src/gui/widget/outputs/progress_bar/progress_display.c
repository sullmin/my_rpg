/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-09T18:21:45+02:00 | Author: simon
*/

#include "my_rpg.h"

int progress_display(progress_t *progress, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, progress->rect_back, NULL);
    sfRenderWindow_drawRectangleShape(window, progress->rect_front, NULL);
    sfRenderWindow_drawText(window, progress->text, NULL);
    return EXIT_SUCCESS;
}
