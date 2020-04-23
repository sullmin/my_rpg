/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:16:37+02:00 | Author: simon
*/

#ifndef H_QUEST_MENU
#define H_QUEST_MENU

#include "quest_menu_t.h"

int menu_quest_create(game_t *game);
void menu_quest_destroy(game_t *game);

int menu_quest_reload(game_t *game);

void menu_quest_display(game_t *game);
void menu_quest_event(game_t *game, sfEvent *event);

// SUB FUNCTIONS
void menu_quest_unload(game_t *game);
int menu_quest_load(game_t *game);

#endif
