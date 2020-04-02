/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "inventory_system.h"

void destroy_item(item_t *item)
{
    if (item->name)
        free(item->name);
    if (item->description)
        free(item->description);
    if (item->sprite)
        sfSprite_destroy(item->sprite);
    if (item->texture)
        sfTexture_destroy(item->texture);
    if (item->particule.framebuffer->pixels)
        free(item->particule.framebuffer->pixels);
    if (item->particule.framebuffer)
        free(item->particule.framebuffer);
}