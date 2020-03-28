/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:56:44+01:00 | Author: simon
*/

#include "my.h"

static const char *USAGES =
"Options:\n"
"\t-h\tDisplay the help\n";

int usage(int status, const char *program_name)
{
    my_putstr("Usage:\t");
    my_putstr(program_name);
    my_putstr("\n");
    my_putstr(USAGES);
    return status;
}
