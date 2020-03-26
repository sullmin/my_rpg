/*
** EPITECH PROJECT, 2020
** config_manager
** File description:
** Created: 2020-03-26T15:51:30+01:00 | Author: simon
*/

#include "config_manager.h"

static void replace_hash(char *line)
{
    if (!line)
        return;
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            line[i] = '\0';
            break;
        }
    }
}

int clean_file_lines(char **file, const char *filepath)
{
    int ret;

    for (size_t i = 0; file[i] != NULL; i++) {
        ret = is_correct_line(file[i]);
        if (ret == EXIT_FAILURE) {
            free(file[i]);
            file[i] = NULL;
        } else if (ret == EXIT_ERROR) {
            my_printf("%s%s", RED_C, BOLD_T);
            my_printf("config_manager : syntax error in \"%s\"", filepath);
            my_printf(" on line %u.%s\n", i, DEFAULT_T);
            return EXIT_ERROR;
        } else {
            replace_hash(file[i]);
        }
    }
    return EXIT_SUCCESS;
}
