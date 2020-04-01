/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_button
*/

#include "my_rpg.h"

void display_button(button_t *button, sfRenderWindow *window)
{
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, button->texture[button->toggle], sfTrue);
    sfSprite_setPosition(sprite, button->pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}
//if (my_button->name)
//    sfRenderWindow_drawText(window, my_button->text, NULL);
//if (my_button->is_activate)
//    sfSound_play(my_button->sound.sound);