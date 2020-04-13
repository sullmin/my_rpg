/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_button
*/

#include "my_rpg.h"

int event_button(button_t *my_button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= my_button->pos.x &&
        mouse_pos.x <= my_button->pos.x + my_button->scale.x &&
        mouse_pos.y >= my_button->pos.y &&
        mouse_pos.y <= my_button->pos.y + my_button->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            my_button->is_activate = true;
            my_button->toggle = 2;
            return 2;
        }
        else {
            my_button->toggle = 1;
            return 1;
        }
    } else {
        my_button->toggle = 0;
        return 0;
    }
}