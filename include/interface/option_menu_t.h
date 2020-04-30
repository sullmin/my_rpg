/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_menu_t
*/

#ifndef OPTION_MENU_T_H_
#define OPTION_MENU_T_H_

#include "button.h"

typedef struct option_menu {
    button_t *azerty;
    button_t *qwerty;
    button_t *keypad;
    button_t *main_menu;
    slider_t *sound;
    sfSprite *spr_background;
    sfTexture *txr_background;
    button_t *chara1;
    button_t *chara2;
} option_menu_t;

#endif /* !OPTION_MENU_T_H_ */
