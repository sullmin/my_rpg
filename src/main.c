/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my_rpg.h"

int main(void)
{
    sound_manager_t sm;
    sound_manager_create(&sm, 20, "asset/sound/", true);
    sound_manager_destroy(&sm);
    return EXIT_SUCCESS;
}
