/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-22T19:06:24+02:00 | Author: simon
*/

#include "my_rpg.h"

void menu_quest_event(game_t *game, sfEvent *event)
{
    (void)event;
    event_button(MENU_QUEST.exit, WINDOW);
    if (MENU_QUEST.exit->toggle == 2 || is_key_released(event, sfKeyO)) {
        game->submenu = NO_MENU;
    }
}
