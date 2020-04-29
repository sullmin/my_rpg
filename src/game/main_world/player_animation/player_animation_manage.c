/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "movement.h"
#include "my_rpg.h"

bool movement_creat(chara_animation_t *mov, const char *sprite)
{
    mov->sprite = sfSprite_create();
    mov->texture = sfTexture_createFromFile(sprite, NULL);
    if (!mov->sprite || !mov->texture)
        return false;
    mov->clock = sfClock_create();
    sfSprite_setPosition(mov->sprite, (sfVector2f) {1120, 360});
    sfSprite_setTexture(mov->sprite, mov->texture, sfTrue);
    sfSprite_setScale(mov->sprite, (sfVector2f) {2, 2});
    for (size_t i = 0; i < 4; i++)
        mov->orient[i] = false;
    mov->orient[3] = true;
    mov->in_move = true;
    return true;
}

void destroy_movement(chara_animation_t *mov)
{
    sfSprite_destroy(mov->sprite);
    sfTexture_destroy(mov->texture);
    sfClock_destroy(mov->clock);
}
