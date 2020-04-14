/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-09T18:21:45+02:00 | Author: simon
*/

#include "my_rpg.h"

static const sfColor COLOR_FRONT = (sfColor) {255, 0, 0, 255};
static const sfColor COLOR_BACK = (sfColor) {0, 0, 0, 255};
static const sfColor COLOR_TEXT = (sfColor) {255, 255, 225, 255};
static const unsigned int TEXT_SIZE = 20;
static const char *FONT_PATH = "./asset/font/BebasNeue-Regular.ttf";
static const unsigned int DEF_PERCENT = 50;

static int create_rect(progress_t *progress, sfVector2f *size,
sfVector2f *position)
{
    progress->rect_back = sfRectangleShape_create();
    progress->rect_front = sfRectangleShape_create();
    if (!progress->rect_back || !progress->rect_front)
        return EXIT_ERROR;
    sfRectangleShape_setFillColor(progress->rect_back, COLOR_BACK);
    sfRectangleShape_setFillColor(progress->rect_front, COLOR_FRONT);
    sfRectangleShape_setPosition(progress->rect_back, *position);
    sfRectangleShape_setPosition(progress->rect_front, *position);
    sfRectangleShape_setSize(progress->rect_back, *size);
    sfRectangleShape_setSize(progress->rect_front, *size);
    return EXIT_SUCCESS;
}

static int create_text(progress_t *progress, const char *text)
{
    sfVector2f pos = {progress->position.x + 5, progress->position.y + 5};

    progress->font = sfFont_createFromFile(FONT_PATH);
    progress->text = sfText_create();
    if (!progress->text || !progress->font)
        return EXIT_ERROR;
    sfText_setPosition(progress->text, pos);
    sfText_setColor(progress->text, COLOR_TEXT);
    sfText_setCharacterSize(progress->text, TEXT_SIZE);
    sfText_setString(progress->text, text);
    sfText_setFont(progress->text, progress->font);
    return EXIT_SUCCESS;
}

int progress_create(progress_t *progress, sfVector2f size,
sfVector2f position, const char *text)
{
    progress->size = size;
    progress->position = position;
    if (create_rect(progress, &size, &position) == EXIT_ERROR) {
        return puterr("progress : create rect\n", EXIT_ERROR);
    }
    if (create_text(progress, text) == EXIT_ERROR) {
        return puterr("progress : create text\n", EXIT_ERROR);
    }
    progress_set_percentage(progress, DEF_PERCENT);
    return EXIT_SUCCESS;
}

void progress_destroy(progress_t *progress)
{
    sfText_destroy(progress->text);
    sfFont_destroy(progress->font);
    sfRectangleShape_destroy(progress->rect_back);
    sfRectangleShape_destroy(progress->rect_front);
}
