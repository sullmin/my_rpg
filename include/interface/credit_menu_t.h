/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-28T17:57:32+02:00 | Author: simon
*/

#ifndef H_CREDIT_MENU_T
#define H_CREDIT_MENU_T

typedef struct credit_menu {
    sfSprite *spr_front;
    sfSprite *spr_back;
    sfTexture *txr_front;
    sfTexture *txr_back;
    sfVector2f pos_front;
    sfClock *clock;
    sfInt32 timer;
    sfInt32 ms_loop;
    float shift_movement;
} credit_menu_t;

#endif
