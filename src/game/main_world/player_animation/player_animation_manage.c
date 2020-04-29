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
    mov->clock = sfClock_create();
    if (!mov->sprite || !mov->texture)
        return false;
    sfSprite_setPosition(mov->sprite, (sfVector2f) {984, 540});
    sfSprite_setTexture(mov->sprite, mov->texture, sfTrue);
    sfSprite_setScale(mov->sprite, (sfVector2f) {2, 2});
    for (size_t i = 0; i < 4; i++)
        mov->orient[i] = false;
    mov->orient[3] = true;
    mov->in_move = false;
    mov->timer = 0;
    mov->rec = (sfIntRect) {0, 0, 32, 65};
    mov->count = 1;
    return true;
}

void destroy_movement(chara_animation_t *mov)
{
    sfSprite_destroy(mov->sprite);
    sfTexture_destroy(mov->texture);
    sfClock_destroy(mov->clock);
}
