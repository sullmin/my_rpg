/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** image viewer
*/

#include "my_rpg.h"

int image_viewer_status(img_view_t *self)
{
    if (!self)
        return EXIT_FAILURE;
    self->is_enable = !(self->is_enable);
    sfRenderWindow_setVisible(self->window, (sfBool)self->is_enable);
    if (self->is_enable) {
        sfRenderWindow_setActive(self->window, sfTrue);
        sfRenderWindow_requestFocus(self->window);
    }
    return EXIT_SUCCESS;
}
