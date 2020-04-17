/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "stdlib.h"

static char *get_size(int nb) {
    size_t size = 1;

    for (size = 1; nb > 10 ; size++)
        nb /= 10;
    return malloc(sizeof(char) * (size + 1));
}

char *myrevgetnbr(int nb)
{
    int i = 1;
    int u = 0;
    char *tab = get_size(nb);

    if (!tab)
        return NULL;
    (nb < 0) ? tab[u] = '-', nb = -nb, u++ : nb;
    if (nb == 0) {
        tab[u] = 48;
        u++;
    }
    for (size_t p; nb >= i; p++)
        i = i * 10;
    i = i / 10;
    for (; i > 0; u++) {
        tab[u] = (nb / i % 10 + '0');
        i = i / 10;
    }
    tab[u] = '\0';
    return (tab);
}