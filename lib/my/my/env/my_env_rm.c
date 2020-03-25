/*
** EPITECH PROJECT, 2020
** LIBMY
** File description:
** variable environment : remove an entry
*/

#include "my.h"

int my_env_rm(env_t *self, const char *label)
{
    char **ptr = my_env_get_ptr(self, label);

    if (ptr == NULL) {
        return EXIT_ERROR;
    }
    free(*ptr);
    *ptr = NULL;
    return EXIT_SUCCESS;
}
