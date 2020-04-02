/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T10:05:35+02:00 | Author: simon
*/

#include "my_rpg.h"

static const float BACK_HEIGHT = 200.0f;
static const float TEXT_SHIFT_X = 10.0f;
static const float TEXT_SHIFT_Y = 10.0f;

static void set_back(game_t *game)
{
    sfRectangleShape *rect = game->sysquest.back;
    sfVector2f size;
    sfVector2f position;

    size.x = game->w.width;
    size.y = BACK_HEIGHT;
    position.x = 0;
    position.y = game->w.height - size.y;
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, position);
}

static void set_text(game_t *game)
{
    sfVector2f position;

    position.x = TEXT_SHIFT_X;
    position.x = TEXT_SHIFT_Y + (game->w.height - BACK_HEIGHT);
    sfText_setPosition(game->sysquest.text, position);
}

int dialogue_display(game_t *game)
{
    sys_quest_t *sysquest = &game->sysquest;

    set_back(game);
    set_text(game);
    sfRenderWindow_drawRectangleShape(game->w.window, sysquest->back, NULL);
    if (sysquest->curr_sentence != NULL) {
        sfText_setString(sysquest->text, sysquest->curr_sentence);
        sfRenderWindow_drawText(game->w.window, sysquest->text, NULL);
    }
    return EXIT_SUCCESS;
}
