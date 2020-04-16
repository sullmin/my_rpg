/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** inventory system
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "config_manager.h"
#include "stat_t.h"


#define INV_Y_SIZE 111
#define INV_X_SIZE 489
#define INV_SPRITE "./asset/sprite/inventory/inventory.jpg"

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

//PLAYER INVENTORY

//return false if ERR
bool player_inventory_creat(player_inventory_t *inv, env_t *env);
void player_inventory_destroy(player_inventory_t *inv);

//ITEM STRUCT

bool item_dup(const item_t *item, item_t *dest);//return false if ERR
void destroy_item(item_t *item);

//CHAIN LIST FOR WORLD ITEM

list_t *make_list(item_t *first);//return false if ERR
bool add_one(list_t **my_list, item_t *other);//return false if ERR
void distroy_item_list(list_t *list);

item_t *item_load(const char *filepath);
bool item_manage(list_t **list);
void display_inventory(player_inventory_t *inv, sfRenderWindow *window);
bool add_item_in_player_inv(player_inventory_t *inv, item_t *item);

#endif
