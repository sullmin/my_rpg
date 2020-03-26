/*
** EPITECH PROJECT, 2020
** LIBMY
** File description:
** variable environment : remove an entry
*/

#include "my.h"

int my_env_rm(env_t *env, const char *label)
{
    char **new_env = NULL;
    char **ptr = my_env_get_ptr(env, label);
    int size;

    if (ptr == NULL || !env || !label) {
        return EXIT_FAILURE;
    }
    size = (env->size - 1);
    free(*ptr);
    *ptr = NULL;
    new_env = my_env_alloc(env->var, NULL, size, size);
    if (!new_env)
        return EXIT_ERROR;
    my_env_destroy(env);
    env->var = new_env;
    env->size = size;
    return EXIT_SUCCESS;
}
