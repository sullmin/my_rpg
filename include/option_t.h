/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_t
*/

#ifndef OPTION_T_H_
#define OPTION_T_H_

#include "move_t.h"

#define LEFT_KEY option->move->left
#define RIGHT_KEY option->move->right
#define UP_KEY option->move->forward
#define DOWN_KEY option->move->backward

typedef struct option_s
{
    move_t *move;
    float volume;
    //const char *langugae
} option_t;

#endif /* !OPTION_T_H_ */
