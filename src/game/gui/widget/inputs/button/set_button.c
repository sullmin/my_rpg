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

int set_button_label(button_t *button, char *str, const char *font_path,
    float size_char)
{
    sfVector2f pos = {button->pos.x + 30, button->pos.y + 5};
    button->text = sfText_create();
    button->font = sfFont_createFromFile(font_path);

    if (!str || !button->font)
        return EXIT_ERROR;
    button->name = my_strdup(str);
    if (!button->name)
        return EXIT_ERROR;
    sfText_setString(button->text, str);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, size_char);
    sfText_setPosition(button->text, pos);
    return EXIT_SUCCESS;
}