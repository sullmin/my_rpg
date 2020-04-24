/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** is_key_released
*/

#include "my_rpg.h"

bool is_key_released(sfEvent *event, sfKeyCode key)
{
    if (event->type == sfEvtKeyReleased && event->key.code == key) {
        return true;
    }
    return false;
}

bool is_key_pressed(sfEvent *event, sfKeyCode key)
{
    if (event->type == sfEvtKeyPressed && event->key.code == key) {
        return true;
    }
    return false;
}
