/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:16:37+02:00 | Author: simon
*/

#ifndef H_QUEST_MENU
#define H_QUEST_MENU

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
} quest_menu_t;

int menu_quest_create(game_t *game);
void menu_quest_destroy(game_t *game);

int menu_quest_load(game_t *game);
void menu_quest_unload(game_t *game);

#endif
