/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-09T18:17:19+02:00 | Author: simon
*/

#ifndef H_PROGRESS
#define H_PROGRESS

typedef struct output_progress_bar {
    sfVector2f size;
    sfVector2f position;
    unsigned int percentage;
    sfRectangleShape *rect_back;
    sfRectangleShape *rect_front;
    sfText *text;
    sfFont *font;
} progress_t;

int progress_create(progress_t *progress, sfVector2f size,
sfVector2f position, const char *text);

void progress_destroy(progress_t *progress);

int progress_set_percentage(progress_t *progress, unsigned int percent);

int progress_display(progress_t *progress, sfRenderWindow *window);

int progress_set_color_back(progress_t *progress, sfColor color);
int progress_set_color_front(progress_t *progress, sfColor color);

#endif
