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
#include "my_rpg.h"


#define INV_Y_SIZE 111
#define INV_X_SIZE 489
#define INV_SPRITE "./asset/sprite/inventory/inventory.jpg"

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
void display_only_inventory(game_t *game);
void display_item_stat(sfRenderWindow *window,
    display_stat_t *info, stat_t *stat);

bool add_item_in_player_inv(player_inventory_t *inv, item_t *item);
bool move_item_in_inventory(game_t *game, const char *id);

bool is_in_player_inv(player_inventory_t *inv, const char *id);
void empty_slot(player_inventory_t *inv, const size_t slot);
bool get_loot(game_t *game);
void set_color_key(list_t *end);
void stat_inv(sfRenderWindow *window, display_stat_t *info,
    player_inventory_t *inv);
void compare_item(sfRenderWindow *window, display_stat_t *info, stat_t *stat);

void level_up(game_t *game);

#endif
