/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** math
*/

#ifndef MATH_H_
#define MATH_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <math.h>

bool point_is_on_circle(sfVector2i point, float radius, sfVector2f position);
float point_length(sfVector2f a, sfVector2f b);
bool point_is_on_triangle(sfVector2f a, sfVector2f b, sfVector2f c,
sfVector2f p);

#endif /* !MATH_H_ */
