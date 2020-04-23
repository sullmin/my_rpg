/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:06:24+02:00 | Author: simon
*/

#include "my_rpg.h"

int menu_quest_reload(game_t *game)
{
    menu_quest_unload(game);
    return menu_quest_load(game);
}
