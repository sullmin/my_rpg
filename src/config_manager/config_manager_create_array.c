/*
** EPITECH PROJECT, 2020
** config_manager
** File description:
** Created: 2020-03-25T19:43:39+01:00 | Author: simon
*/

#include "config_manager.h"

static int get_line_len(const char *line)
{
    int len = 0;
    bool is_str = false;

    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"') {
            is_str = true;
        } else if (is_str || (line[i] != ' ' && line[i] != '\t')) {
            len++;
        }
    }
    return len;
}

static void line_cpy(char *dest, const char *src)
{
    size_t idx_dest = 0;
    bool is_str = false;

    for (size_t i = 0; src[i] != '\0'; i++) {
        if (src[i] == '"') {
            is_str = true;
        } else if (is_str || (src[i] != ' ' && src[i] != '\t')) {
            dest[idx_dest] = src[i];
            idx_dest++;
        }
    }
}

static char *line_dup(const char *line)
{
    char *ret = NULL;
    int len = get_line_len(line);

    ret = malloc(sizeof(char) * (len + 1));
    if (ret == NULL)
        return NULL;
    line_cpy(ret, line);
    ret[len] = '\0';
    return ret;
}

static int get_file_array_len(char **file_content, int size)
{
    int len = 0;

    for (ssize_t i = 0; i < size; i++) {
        if (file_content[i] != NULL)
            len++;
    }
    return len;
}

char **config_manager_create_array(char **file_content, int size)
{
    int conf_array_len = get_file_array_len(file_content, size);
    char **conf = NULL;
    int idx = 0;

    conf = malloc(sizeof(char *) * (conf_array_len + 1));
    if (!conf)
        return NULL;
    for (ssize_t i = 0; i < size; i++) {
        if (file_content[i] == NULL)
            continue;
        conf[idx] = line_dup(file_content[i]);
        if (!conf[idx])
            return NULL;
        idx++;
    }
    conf[conf_array_len] = NULL;
    return conf;
}
