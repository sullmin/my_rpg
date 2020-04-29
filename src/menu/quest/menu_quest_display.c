/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:06:24+02:00 | Author: simon
*/

#include "my_rpg.h"

static void draw_quest_el(quest_ui_t *el, game_t *game)
{
    sfRenderWindow_drawRectangleShape(WINDOW, el->back, NULL);
    sfRenderWindow_drawText(WINDOW, el->title, NULL);
    sfRenderWindow_drawText(WINDOW, el->description, NULL);
}

void menu_quest_display(game_t *game)
{
    sfRenderWindow_drawSprite(WINDOW, MENU_QUEST.spr_background, NULL);
    display_button(MENU_QUEST.exit, WINDOW);
    for (size_t i = 0; i < MENU_QUEST.ui_size
            && i < (size_t)MENU_QUEST.max_display; i++) {
        draw_quest_el(&MENU_QUEST.ui_element[i], game);
    }
}
