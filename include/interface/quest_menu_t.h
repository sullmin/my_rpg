/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:16:37+02:00 | Author: simon
*/

#ifndef H_QUEST_MENU_T
#define H_QUEST_MENU_T

typedef struct quest_ui {
    sfRectangleShape *back;
    sfText *title;
    sfText *description;
    sfVector2f position;
} quest_ui_t;

typedef struct quest_menu {
    sfTexture *txr_background;
    sfSprite *spr_background;
    button_t *exit;
    quest_ui_t *ui_element;
    size_t ui_size;
    size_t ignore;
    int max_display;
} quest_menu_t;

#endif
