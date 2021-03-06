/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_button
*/

#include "my_rpg.h"

int set_button_texture(button_t *my_button, const char **filepath)
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

int set_button_label(button_t *button, const char *str, const char *font_path,
    float size_char)
{
    sfVector2f pos = {button->pos.x + 30, button->pos.y + 5};

    button->text = sfText_create();
    button->font = sfFont_createFromFile(font_path);
    if (!str || !button->font || !button->text)
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

int set_button_helpbox(button_t *button, const char *str,
const char *font_path)
{
    button->help_box = malloc(sizeof(help_box_t));
    if (button->help_box == NULL)
        return EXIT_ERROR;
    button->help_box->font = sfFont_createFromFile(font_path);
    button->help_box->text = sfText_create();
    if (!str || !button->help_box->font || !button->help_box->text)
        return EXIT_ERROR;
    sfText_setString(button->help_box->text, str);
    sfText_setFont(button->help_box->text, button->help_box->font);
    sfText_setCharacterSize(button->help_box->text, SIZE_HELP_BOX);
    return EXIT_SUCCESS;
}

int set_button_sound(button_t *button, const char *filepath)
{
    button->sound = malloc(sizeof(sound_t));
    if (button->sound == NULL)
        return EXIT_ERROR;
    button->sound->buffer = sfSoundBuffer_createFromFile(filepath);
    button->sound->sound = sfSound_create();
    if (button->sound->sound == NULL || button->sound->buffer == NULL)
        return EXIT_ERROR;
    sfSound_setBuffer(button->sound->sound, button->sound->buffer);
    return EXIT_SUCCESS;
}
