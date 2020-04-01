/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_button
*/

#include "my_rpg.h"

int set_texture_button(button_t *my_button, const char **filepath)
{
    my_button->texture = malloc(sizeof(sfTexture *) * NB_BUTTON_STATE);
    if (!my_button->texture)
        return EXIT_ERROR;
    for (size_t i = 0; i < NB_BUTTON_STATE; i++) {
        if (filepath[i] == NULL)
            return EXIT_ERROR;
        my_button->texture[i] = sfTexture_createFromFile(filepath[i], NULL);
        if (my_button->texture[i] == NULL)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}