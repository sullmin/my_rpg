/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory system
*/

#ifndef INVENTORY_T_H
#define INVENTORY_T_H

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

//ITEM STRUCT

typedef struct {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct particule_effect_s
{
    framebuffer_t *framebuffer;
} particule_effect_t;

typedef struct item_s
{
    char id[4];
    char *name;
    char *description;
    bool av_particule;
    bool is_equiped;
    sfVector2i pos;
    sfVector2f size;
    sfSprite *sprite;
    sfTexture *texture;
    particule_effect_t particule;
    stat_t stats;
} item_t;

//CHAIN LIST FOR WORLD ITEM

typedef struct list_s
{
    struct list_s *next;
    item_t *item;
} list_t;

//PLAYER INVENTORY

typedef struct player_inventory_s
{
    item_t **inventory;
    size_t size;
    size_t nb_item;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} player_inventory_t;

#endif