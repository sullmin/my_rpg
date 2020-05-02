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

static bool init_values(player_inventory_t *inv, env_t *env)
{
    bool err = false;

    my_env_get_value_int(env, "INVENTORY_POSX", &err);
    my_env_get_value_int(env, "INVENTORY_POSY", &err);
    inv->pos.x = 0;
    inv->pos.y = 0;
    if (err) {
        return false;
    }
    return true;
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
    inv->equiped = NULL;
    inv->sprite = sfSprite_create();
    inv->texture = sfTexture_createFromFile(INV_SPRITE, NULL);
    if (!inv->texture || !inv->sprite)
        return false;
    sfSprite_setTexture(inv->sprite, inv->texture, sfTrue);
    if (err)
        return false;
    sfSprite_setPosition(inv->sprite, inv->pos);
    return init_values(inv, env);
}

void player_inventory_destroy(player_inventory_t *inv)
{
    free(inv->inventory);
    sfSprite_destroy(inv->sprite);
    sfTexture_destroy(inv->texture);
}
