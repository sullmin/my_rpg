/*
** EPITECH PROJECT, 2020
** LIBMY
** File description:
** Created: 2020-03-25T14:34:11+01:00 | Author: simon
*/

#ifndef H_ENV
#define H_ENV

#include "env_t.h"

void my_env_destroy(env_t *env);
int my_env_create(env_t *env, char **copy_env);
int my_env_merge(env_t *env, char **env_src);

int my_env_update(env_t *self, const char *label, const char *value);
int my_env_rm(env_t *self, const char *label);
char *my_env_get(env_t *self, const char *label);
char **my_env_get_ptr(env_t *self, const char *label);
int my_env_add(env_t *self, const char *label, const char *value);

char **my_env_alloc(char **src, env_t *old, int new_size, int src_size);

char *my_env_get_value(env_t *env, const char *label);
int my_env_get_value_int(env_t *env, const char *label);
double my_env_get_value_double(env_t *env, const char *label);
char *my_env_get_var_value(char *entry);
char *my_env_get_var_label(char *entry);

int my_env_size(env_t *env);

void my_env_display(env_t *env);

#endif
