/*
** EPITECH PROJECT, 2020
** config_manager
** File description:
** Created: 2020-03-26T16:12:35+01:00 | Author: simon
*/

#ifndef H_CONF_MANAGER
#define H_CONF_MANAGER

#include "my.h"

int config_manager_read(env_t *env, const char *filepath);
void config_manager_destroy(env_t *env);
env_t config_manager_create(void);

// SUB FUNCTIONS
int clean_file_lines(char **file, const char *filepath);
int is_correct_line(char *line);
char **config_manager_create_array(char **file_content, int size);

#endif
