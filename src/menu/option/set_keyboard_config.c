/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_keyboard_config
*/

#include "my_rpg.h"

int set_keyboard_config(option_t *option, const int *keyconfig)
{
    option->move->forward = keyconfig[0];
    option->move->left = keyconfig[1];
    option->move->backward = keyconfig[2];
    option->move->right = keyconfig[3];
    return EXIT_SUCCESS;
}
