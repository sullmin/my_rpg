/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_t
*/

#ifndef MAIN_MENU_T_H_
#define MAIN_MENU_T_H_

#include "button.h"

typedef struct main_menu {
    button_t *play;
    button_t *quit;
    button_t *option;
} main_menu_t;

#endif /* !MAIN_MENU_T_H_ */
