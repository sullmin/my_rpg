/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T10:05:35+02:00 | Author: simon
*/

#include "my_rpg.h"

static const char *EXT_FILE_DIALOGUE = ".diag";
static const char *PATH_FILE_DIALOGUE = "./asset/dialogue/";

int dialogue_load(list_str_t **dialogue, const char *file)
{
    char **content = NULL;
    char *filepath = my_str_concat(PATH_FILE_DIALOGUE, file);

    if (!file || !filepath)
        return EXIT_ERROR;
    else if (!my_file_ext_cmp(file, EXT_FILE_DIALOGUE)) {
        return puterr("dialogue_load : wrong file extension\n", EXIT_ERROR);
    }
    content = my_read_file(filepath);
    free(filepath);
    if (!content)
        return puterr("dialogue_load : fail to read diag file\n", EXIT_ERROR);
    if (word_array_len(content) == 0)
        return puterr("dialogue_load : invalid size file\n", EXIT_ERROR);
    for (size_t i = 0; content[i] != NULL; i++) {
        if (my_str_list_add(dialogue, content[i]) == EXIT_ERROR)
            return puterr("dialogue_load : list add error\n", EXIT_ERROR);
    }
    return EXIT_SUCCESS;
}
