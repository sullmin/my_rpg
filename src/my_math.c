/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_math
*/


#include "my_math.h"

bool point_is_on_circle(sfVector2i point, float radius, sfVector2f position)
{
    sfVector2f center = {.x = position.x + radius, .y = position.y + radius};
    float distance = 0;
    float pow_x = powf(point.x - center.x , 2);
    float pow_y = powf(center.y - point.y, 2);

    distance = sqrt(pow_x + pow_y);
    if (distance < radius)
        return true;
    return false;
}