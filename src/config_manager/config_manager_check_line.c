/*
** EPITECH PROJECT, 2020
** config_manager
** File description:
** Created: 2020-03-26T15:51:30+01:00 | Author: simon
*/

#include "config_manager.h"

static bool jump_char(char **str, const char *chars, bool inverse)
{
    bool have_move = false;

    for (; (*(*str)) != '\0'; (*str)++) {
        if (inverse && !(my_str_have_char(chars, *(*str)) != -1)) {
            have_move = true;
        } else if (!inverse && (my_str_have_char(chars, *(*str)) != -1)) {
            have_move = true;
        } else {
            return have_move;
        }
    }
    return have_move;
}

static bool check_line_parta(char **line_ptr)
{
    jump_char(line_ptr, " \t", false);
    if (jump_char(line_ptr, " \t=#", true) == false) {
        return false;
    }
    jump_char(line_ptr, " \t", false);
    if (*(*line_ptr) != '=') {
        return false;
    } else {
        (*line_ptr)++;
    }
    return true;
}

static bool check_line_partb(char **line_ptr)
{
    jump_char(line_ptr, " \t", false);
    if (jump_char(line_ptr, " \t=#", true) == false) {
        return false;
    }
    jump_char(line_ptr, " \t", false);
    if (*(*line_ptr) != '\0' && *(*line_ptr) != '#') {
        return false;
    }
    return true;
}

static bool is_empty_line(char *line)
{
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            return true;
        } else if (my_str_have_char(" \t", line[i]) == -1) {
            return false;
        }
    }
    return true;
}

int is_correct_line(char *line)
{
    bool ret;
    char *line_ptr = line;

    if (!line)
        return EXIT_ERROR;
    ret = check_line_parta(&line_ptr);
    if (ret != false) {
        ret = check_line_partb(&line_ptr);
    }
    if (ret == false) {
        if (is_empty_line(line)) {
            return EXIT_FAILURE;
        } else {
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}
