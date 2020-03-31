/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "inventory_system.h"

static void stat_dup(const stat_t *stat, stat_t *dest)
{
    dest->agility = stat->agility;
    dest->strength = stat->strength;
    dest->speed = stat->speed;
    dest->health = stat->health;
    dest->resistance = stat->resistance;
    dest->iq = stat->iq;
}

static bool effect_dup(const particule_effect_t *eff,
    particule_effect_t *dest)
{
    int p;

    dest->framebuffer = malloc(sizeof(framebuffer_t));
    if (!dest->framebuffer)
        return false;
    dest->framebuffer->width = eff->framebuffer->width;
    dest->framebuffer->height = eff->framebuffer->height;
    dest->framebuffer->pixels = malloc(width * height * 32);
    if (!dest->framebuffer->pixels)
        return false;
    for (size_t y = 0; y < dest->framebuffer->height; y++)
        for (size_t x = 0; x < dest->framebuffer->width; x++) {
            p = (x + y * dest->framebuffer->width) * 4;
            dest->framebuffer->pixels[p] = eff->framebuffer->pixels[p];
            dest->framebuffer->pixels[p + 1] = eff->framebuffer->pixels[p + 1];
            dest->framebuffer->pixels[p + 2] = eff->framebuffer->pixels[p + 2];
            dest->framebuffer->pixels[p + 3] = eff->framebuffer->pixels[p + 3];
        }
    return true;
}

bool item_dup(const item_t *item, item_t *dest)
{
    if (!item->name) {
        dest->name = NULL;
        return true;
    }
    dest->name = my_strdup(item->name);
    dest->description = my_strdup(item->description);
    dest->sprite = sfSprite_copy(item->sprite);
    dest->texture = sfTexture_copy(item->texture);
    if (!dest->name || !dest->description || !dest->texture || !dest->sprite)
        return false;
    dest->av_particule = item->av_particule;
    dest->is_equiped = item->is_equiped;
    dest->pos = item->pos;
    dest->size = item->size;
    stat_dup(&item->stat, &dest->stat);
    if (!effect_dup(&item->particule, &dest->particule))
        return false;
    return true;
}