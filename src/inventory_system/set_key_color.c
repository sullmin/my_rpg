/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"

void set_color_key(list_t *end)
{
    while (end) {
        if (my_strcmp(end->item->id, "213") == 0)
            sfSprite_setColor(end->item->sprite, sfGreen);
        if (my_strcmp(end->item->id, "313") == 0)
            sfSprite_setColor(end->item->sprite, sfRed);
        if (my_strcmp(end->item->id, "413") == 0)
            sfSprite_setColor(end->item->sprite, sfWhite);
        end = end->next;
    }
}