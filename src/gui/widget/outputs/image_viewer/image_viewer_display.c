/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** image viewer
*/

#include "my_rpg.h"

static void image_viewer_event_manager(img_view_t *self, sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        image_viewer_status(self);
    } else if (event->type == sfEvtKeyPressed) {
        image_viewer_status(self);
    }
}

int image_viewer_display(img_view_t *self)
{
    sfEvent event;

    if (!self || !self->sprite || !self->is_enable)
        return EXIT_FAILURE;
    while (sfRenderWindow_pollEvent(self->window, &event))
        image_viewer_event_manager(self, &event);
    sfRenderWindow_clear(self->window, sfBlack);
    sfRenderWindow_drawSprite(self->window, self->sprite, NULL);
    sfRenderWindow_display(self->window);
    return EXIT_SUCCESS;
}
