/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory system
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "stat_t.h"

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
    //char id[4];
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
} player_inventory_t;

//PLAYER INVENTORY

bool get_player_inventory(player_inventory_t *inv, env_t *env);//return false if ERR

//ITEM STRUCT

bool item_dup(const item_t *item, item_t *dest);//return false if ERR
void destroy_item(item_t *item);

//CHAIN LIST FOR WORLD ITEM

list_t *make_list(item_t *first);//return false if ERR
bool add_one(list_t *my_list, item_t *other);//return false if ERR
void distroy(list_t *list);

#endif
