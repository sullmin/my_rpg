/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** image viewer
*/

#include "my_rpg.h"

static const int IMG_VIEW_WIN_BPP = 32;
static const int IMG_VIEW_WIN_FRAMERATE = 20;

static int image_viewer_create_window(img_view_t *self)
{
    sfVideoMode mode = {self->size.x, self->size.y, IMG_VIEW_WIN_BPP};

    self->window = sfRenderWindow_create(mode, self->title, sfClose,
    sfContextDefault);
    if (!self->window) {
        my_putstr_error("image_viewer_create_window : error.\n");
        return EXIT_FAILURE;
    }
    sfRenderWindow_setFramerateLimit(self->window, IMG_VIEW_WIN_FRAMERATE);
    sfRenderWindow_setVisible(self->window, sfFalse);
    return EXIT_SUCCESS;
}

int image_viewer_create(img_view_t *self, const char *file_name,
const char *title)
{
    if (!self || !file_name)
        return EXIT_FAILURE;
    self->title = my_strdup(title);
    self->is_enable = false;
    self->file_path = my_strdup(file_name);
    self->texture = sfTexture_createFromFile(file_name, NULL);
    if (!self->texture || !self->title || !self->file_path) {
        my_putstr_error("image_viewer_create : error\n");
        self->sprite = NULL;
        return EXIT_FAILURE;
    }
    self->sprite = sfSprite_create();
    sfSprite_setTexture(self->sprite, self->texture, sfTrue);
    self->window = NULL;
    self->size = sfTexture_getSize(self->texture);
    if (image_viewer_create_window(self) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void image_viewer_destroy(img_view_t *self)
{
    sfTexture_destroy(self->texture);
    sfRenderWindow_destroy(self->window);
    sfSprite_destroy(self->sprite);
    free(self->title);
    free(self->file_path);
}
