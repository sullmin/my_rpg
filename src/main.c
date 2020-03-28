/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main function
*/

#include "my_rpg.h"

int main(int argc, char **argv)
{
    if (argc > 1) {
        return usage(EXIT_SUCCESS, argv[0]);
    } else {
        return master();
    }
    return EXIT_SUCCESS;
}
