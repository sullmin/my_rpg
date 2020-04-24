/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "movement.h"
#include "my_rpg.h"

bool movement_creat(movement_t *mov)
{
    mov->sprite = sfSprite_create();
    mov->texture = sfTexture_createFromFile("./asset/sprite/hero.png", NULL);
    if (!mov->sprite || !mov->texture)
        return false;
    mov->clock = sfClock_create();
    sfSprite_setPosition(mov->sprite, (sfVector2f) {100, 100});
    sfSprite_setTexture(mov->sprite, mov->texture, sfTrue);
    for (size_t i = 0; i < 4; i++)
        mov->orient[i] = false;
    mov->orient[3] = true;
    mov->in_move = true;
    return true;
}

void destroy_movement(movement_t *mov)
{
    sfSprite_destroy(mov->sprite);
    sfTexture_destroy(mov->texture);
    sfClock_destroy(mov->clock);
}