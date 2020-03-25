/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** variable environment : realloc the environment
*/

#include "my.h"

static char **env_alloc(int size)
{
    char **new_env = malloc(sizeof(char *) * (size + 1));

    if (!new_env) {
        my_putstr_error("ERROR: env_alloc : malloc error\n");
        return NULL;
    }
    for (ssize_t i = 0; i <= size; i++) {
        new_env[i] = NULL;
    }
    return new_env;
}

static int env_dup(char **src, char **dest, int dest_size,
int src_size)
{
    int idx_dest = 0;

    for (ssize_t i = 0; i < src_size; i++) {
        if (src[i] != NULL && idx_dest < dest_size) {
            dest[idx_dest++] = my_strdup(src[i]);
        }
        if (src[i] != NULL && idx_dest < dest_size && !dest[idx_dest - 1]) {
            my_putstr_error("ERROR: malloc error (env_dup)\n");
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

char **my_env_alloc(char **src, int new_size, int src_size)
{
    char **new_env = env_alloc(new_size);

    if (!new_env) {
        return NULL;
    }
    if (src == NULL) {
        return new_env;
    } else if (env_dup(src, new_env, new_size, src_size) == EXIT_ERROR) {
        return NULL;
    }
    return new_env;
}
