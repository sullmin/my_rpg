/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

float as_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);

    return (float)time.microseconds / 1000000.f;
}