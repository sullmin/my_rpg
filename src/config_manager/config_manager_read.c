/*
** EPITECH PROJECT, 2020
** config_manager
** File description:
** Created: 2020-03-25T19:43:39+01:00 | Author: simon
*/

#include "config_manager.h"

static void file_content_destroy(char **file, int size)
{
    for (ssize_t i = 0; i < size; i++) {
        free(file[i]);
    }
    free(file);
}

static int config_manager_get_file_content(char ***file_content,
const char *filepath, int *len_content)
{
    if (!my_file_ext_cmp(filepath, ".conf")) {
        my_printf("%s%sconfig_manager : invalid file ", RED_C, BOLD_T);
        my_printf("extension \"%s\"%s\n", filepath, DEFAULT_T);
        return EXIT_ERROR;
    }
    *file_content = my_read_file(filepath);
    if (!file_content) {
        my_printf("%s%sconfig_manager : cannot open/read file", RED_C, BOLD_T);
        my_printf(" \"%s\"%s\n", filepath, DEFAULT_T);
        return EXIT_ERROR;
    }
    *len_content = word_array_len(*file_content);
    return EXIT_SUCCESS;
}

static int config_manager_apply_config(char **file_content, env_t *env,
int len)
{
    char **conf = NULL;

    conf = config_manager_create_array(file_content, len);
    if (!conf)
        return my_puterror("config_manager : malloc error\n", EXIT_ERROR);
    if (my_env_merge(env, conf) == EXIT_ERROR)
        return EXIT_ERROR;
    word_array_destroy(conf);
    return EXIT_SUCCESS;
}

int config_manager_read(env_t *env, const char *filepath)
{
    char **file_content = NULL;
    int len;

    if (!env || !filepath)
        return EXIT_ERROR;
    if (config_manager_get_file_content(&file_content, filepath, &len))
        return EXIT_ERROR;
    if (clean_file_lines(file_content, filepath) == EXIT_ERROR) {
        file_content_destroy(file_content, len);
        return EXIT_ERROR;
    } else if (config_manager_apply_config(file_content, env, len)) {
        return EXIT_ERROR;
    }
    file_content_destroy(file_content, len);
    my_printf("%s%sconfig_manager : \"%s\"", BOLD_T, GREEN_C, filepath);
    my_printf(" loaded.%s\n", DEFAULT_T);
    return EXIT_SUCCESS;
}
