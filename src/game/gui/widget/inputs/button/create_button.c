/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button
*/

#include "my_rpg.h"

button_t *create_button(sfVector2f pos, sfVector2f scale)
{
    button_t *my_button = malloc(sizeof(button_t));

    if (!my_button)
        return NULL;
    my_button->pos = pos;
    my_button->scale = scale;
    my_button->toggle = 0;
    my_button->name = NULL;
    my_button->texture = NULL;
    my_button->is_activate = false;
    my_button->help_box = NULL;
    my_button->sound = NULL;
    return my_button;
}
