/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "inventory_system.h"

static item_t **get_tab_inventory(size_t size)
{
    item_t **inventory;

    if (size <= 0)
        return NULL;
    inventory = malloc(sizeof(item_t *) * size);
    if (!inventory)
        return NULL;
    for (size_t i = 0; i < size; i++)
        inventory[i] = NULL;
    return inventory;
}

bool player_inventory_creat(player_inventory_t *inv, env_t *env)
{
    bool err = false;

    inv->size = my_env_get_value_int(env, "INVENTORY_SIZE", &err);
    if (err || inv->size <= 0)
        return false;
    inv->inventory = get_tab_inventory(inv->size);
    if (!inv->inventory)
        return false;
    inv->nb_item = 0;
    inv->sprite = sfSprite_create();
    inv->texture = sfTexture_createFromFile(INV_SPRITE, NULL);
    if (!inv->texture || !inv->sprite)
        return false;
    sfSprite_setTexture(inv->sprite, inv->texture, sfTrue);
    return true;
}

void player_inventory_destroy(player_inventory_t *inv)
{
    //free item who is in?
    free(inv->inventory);
    sfSprite_destroy(inv->sprite);
    sfTexture_destroy(inv->texture);
}