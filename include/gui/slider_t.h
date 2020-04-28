/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** slider_t
*/

#ifndef SLIDER_T_H_
#define SLIDER_T_H_

typedef struct slider_widget {
    sfColor color;
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfVector2f circle_pos;
    sfVector2f rect_pos;
    sfVector2f rect_size;
    float circle_radius;
    sfBool isPressed;
    int min;
    int max;
} slider_t;

#endif /* !SLIDER_T_H_ */
