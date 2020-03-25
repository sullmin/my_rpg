/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** Task01
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *cpy = NULL;

    if (!src)
        return NULL;
    cpy = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (cpy == NULL)
        return (cpy);
    return (my_strcpy(cpy, src));
}
