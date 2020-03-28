/*
** EPITECH PROJECT, 2020
** config_manager
** File description:
** Created: 2020-03-26T20:34:38+01:00 | Author: simon
*/

#include "config_manager.h"

void config_manager_destroy(env_t *env)
{
    my_env_destroy(env);
}

env_t config_manager_create(void)
{
    env_t env = {NULL, 0};

    return env;
}
