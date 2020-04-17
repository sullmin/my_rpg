/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "display_stat.h"
#include "my_rpg.h"

bool init_display_stat(display_stat_t *info, env_t *env)
{
    info->pos.x = my_env_get_value_int(env, "STAT_POSX", NULL);
    info->pos.y = my_env_get_value_int(env, "STAT_POSY", NULL);
    info->font = sfFont_createFromFile("./asset/font/MADETOMMY-Bold.ttf");
    if (!info->font)
        return false;
    info->sprite = sfSprite_create();
    info->texture = sfTexture_createFromFile(
        my_env_get_value(env, "BACKG_STAT"), NULL);
    if (!info->sprite || !info->texture)
        return false;
    sfSprite_setPosition(info->sprite,
        (sfVector2f) {info->pos.x - 10, info->pos.y - 10});
    sfSprite_setTexture(info->sprite, info->texture, sfTrue);
    return true;
}

void destroy_display_stat(display_stat_t *info)
{
    sfFont_destroy(info->font);
    sfSprite_destroy(info->sprite);
    sfTexture_destroy(info->texture);
}