/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory system
*/

#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct particule_effect_s
{
    framebuffer_t *framebuffer;
} particule_effect_t;

typedef struct stat_s
{
    int agility;
    int strength;
    int speed;
    int health;
    int resistance;
    int iq;
} stat_t;

typedef struct item_s
{
    char *name;
    char *description;
    bool av_particule;
    bool is_equiped;
    sfVector2i pos;
    sfVector2f size;
    sfSprite *sprite;
    sfTexture *texture;
    particule_effect_t particule;
    stat_t stats,
} item_t;

#endif
