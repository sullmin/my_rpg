/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-09T14:06:11+02:00 | Author: simon
*/

#include "my_rpg.h"

int text_input_change_status(text_in_t *input)
{
    sfVector2i pos = {100, 100};

    if (!input)
        return EXIT_ERROR;
    input->is_enable = !input->is_enable;
    sfRenderWindow_setPosition(input->window, pos);
    sfRenderWindow_setVisible(input->window, input->is_enable);
    if (input->is_enable) {
        text_input_set_value(input, "");
        sfRenderWindow_setActive(input->window, sfTrue);
        sfRenderWindow_requestFocus(input->window);
    }
    return EXIT_SUCCESS;
}
