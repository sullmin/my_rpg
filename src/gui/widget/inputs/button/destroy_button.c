/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_button
*/

#include "my_rpg.h"

void destroy_button(button_t *button)
{
    for (size_t i = 0; i < NB_BUTTON_STATE; i++)
        sfTexture_destroy(button->texture[i]);
    free(button->texture);
    if (button->name) {
        free(button->name);
        sfFont_destroy(button->font);
        sfText_destroy(button->text);
    }
    if (button->help_box != NULL) {
        sfFont_destroy(button->help_box->font);
        sfText_destroy(button->help_box->text);
    }
    if (button->sound != NULL) {
        sfSoundBuffer_destroy(button->sound->buffer);
        sfSound_destroy(button->sound->sound);
        free(button->sound);
    }
    free(button);
}