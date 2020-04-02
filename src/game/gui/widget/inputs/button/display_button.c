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
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    sfSprite_setTexture(sprite, button->texture[button->toggle], sfTrue);
    sfSprite_setPosition(sprite, button->pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    if (button->name)
        sfRenderWindow_drawText(window, button->text, NULL);
    if (button->help_box && button->toggle == 1) {
        sfText_setPosition(button->help_box->text,
        (sfVector2f){5 + mouse_pos.x, 5 + mouse_pos.y});
        sfRenderWindow_drawText(window, button->help_box->text, NULL);
    }
}

//if (my_button->is_activate)
//    sfSound_play(my_button->sound.sound);