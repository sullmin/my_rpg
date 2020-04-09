/*
** EPITECH PROJECT, 2020
** MUL_input_widget
** File description:
** text input
*/

#include "my_rpg.h"

char *text_input_get_input(text_in_t *input)
{
    return my_strdup(input->buffer + 1);
}

void text_input_set_value(text_in_t *input, const char *value)
{
    int len_value = my_strlen(value);

    if (!input || !value || !input->buffer) {
        return;
    }
    if (len_value > (int)input->max_char) {
        return;
    }
    my_strcpy((input->buffer + 1), value);
    input->buffer[len_value + 1] = '\0';
    input->i_buffer = (len_value + 1);
    sfText_setString(input->text, input->buffer);
}
