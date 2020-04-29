/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-28T17:54:36+02:00 | Author: simon
*/

#include "my_rpg.h"

void credit_menu_display(game_t *game)
{
    MENU_CREDIT.timer += TIME_MILLI(MENU_CREDIT.clock);
    sfClock_restart(MENU_CREDIT.clock);
    if (MENU_CREDIT.timer >= MENU_CREDIT.ms_loop) {
        MENU_CREDIT.timer = 0;
        MENU_CREDIT.pos_front.y += MENU_CREDIT.shift_movement;
        if (MENU_CREDIT.pos_front.y >= game->w.height) {
            MENU_CREDIT.pos_front.y = -game->w.height;
        }
        sfSprite_setPosition(MENU_CREDIT.spr_front, MENU_CREDIT.pos_front);
    }
    sfRenderWindow_drawSprite(WINDOW, MENU_CREDIT.spr_back, NULL);
    sfRenderWindow_drawSprite(WINDOW, MENU_CREDIT.spr_front, NULL);
}
