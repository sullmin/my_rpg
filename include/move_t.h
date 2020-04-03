/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_t
*/

#ifndef MOVE_T_H_
#define MOVE_T_H_

#include <SFML/Graphics.h>

typedef struct move_s
{
    sfKeyCode forward;
    sfKeyCode backward;
    sfKeyCode left;
    sfKeyCode right;
} move_t;


#endif /* !MOVE_T_H_ */
