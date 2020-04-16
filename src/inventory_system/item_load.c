/*
** EPITECH PROJECT, 2019
** item_load
** File description:
** item_load
*/

#include "inventory_system.h"
#include "config_manager.h"

static void id_load(item_t *item, env_t *my_env)
{
    char *tmp = my_env_get_value(my_env, "ID");

    for (size_t i = 0; i < 4; i++)
        item->id[i] = tmp[i];
    item->id[3] = '\0';
    free(tmp);
}

static void stat_load(item_t *item, env_t *my_env)
{
    item->stats.agility = my_env_get_value_int(my_env, "AGIL", NULL);
    item->stats.speed = my_env_get_value_int(my_env, "SPEED", NULL);
    item->stats.strength = my_env_get_value_int(my_env, "STREN", NULL);
    item->stats.health = my_env_get_value_int(my_env, "HEALTH", NULL);
    item->stats.resistance = my_env_get_value_int(my_env, "RES", NULL);
    item->stats.iq = my_env_get_value_int(my_env, "IQ", NULL);
}

static bool struct_load(item_t *item, env_t *my_env)
{
    item->name = my_env_get_value(my_env, "NAME");
    item->description = my_env_get_value(my_env, "DESC");
    id_load(item, my_env);
    stat_load(item, my_env);
    item->av_particule = my_env_get_value_int(my_env, "AV_PART", NULL);
    item->pos.x = my_env_get_value_int(my_env, "POSX", NULL);
    item->pos.y = my_env_get_value_int(my_env, "POSY", NULL);
    item->size.x = my_env_get_value_dec(my_env, "SIZEX", NULL);
    item->size.y = my_env_get_value_dec(my_env, "SIZEY", NULL);
    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(
        my_env_get_value(my_env, "SPRITE"), NULL);
    if (!item->sprite || !item->texture)
        return false;
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    return true;
}

item_t *item_load(const char *filepath)
{
    env_t my_env = config_manager_create();
    int ret = config_manager_read(&my_env, filepath);
    item_t *item = malloc(sizeof(item_t));

    if (ret == EXIT_ERROR)
        return NULL;
    if (!struct_load(item, &my_env))
        return NULL;
    config_manager_destroy(&my_env);
    return item;
}