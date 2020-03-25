/*
** EPITECH PROJECT, 2020
** LIBMY
** File description:
** variable environment
*/

#include "my.h"

static void get_idx_symbol_and_length(char *env_var, int *len,
int *idx_symbol)
{
    for (int i = 0; env_var[i] != '\0'; i++) {
        if (env_var[i] == '=') {
            *idx_symbol = i;
            break;
        }
        (*len)++;
    }
    if (*idx_symbol == -1) {
        *idx_symbol = my_strlen(env_var) - 1;
    }
}

char *my_env_get_var_value(char *entry)
{
    int first_symb = 0;

    if (!entry)
        return NULL;
    for (size_t i = 0; entry[i] != '\0'; i++) {
        if (!first_symb && entry[i] == '=') {
            first_symb = 1;
        } else if (first_symb) {
            return my_strdup(&(entry[i]));
        }
    }
    return NULL;
}

char *my_env_get_var_label(char *entry)
{
    int len = 0;
    int idx_symbol = -1;
    char *label = NULL;

    if (!entry)
        return NULL;
    get_idx_symbol_and_length(entry, &len, &idx_symbol);
    if (len == 0) {
        return NULL;
    }
    label = malloc(sizeof(char) * len);
    if (!label) {
        my_putstr_error("Error: malloc (get_env_var_label)\n");
        return NULL;
    }
    my_strncpy(label, entry, idx_symbol + 1);
    label[idx_symbol + 1] = '\0';
    return label;
}

char *my_env_get_value(env_t *env, const char *label)
{
    char *entry = my_env_get(env, label);

    if (!entry)
        return NULL;
    return my_env_get_var_value(entry);
}

int my_env_len(env_t *env)
{
    return env->size;
}
