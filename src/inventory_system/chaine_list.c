/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "inventory_system.h"

list_t *make_list(item_t *first)
{
    list_t *start = malloc(sizeof(list_t));

    if (!start)
        return NULL;
    start->next = NULL;
    start->item = first;
    return start;
}

bool add_one(list_t **my_list, item_t *other)
{
    list_t *end = *my_list;

    if (!(*my_list)) {
        *my_list = make_list(other);
        if (!(*my_list))
            return false;
        return true;
    }
    while (end->next)
        end = end->next;
    end->next = malloc(sizeof(list_t));
    if (!end->next)
        return false;
    end->next->next = NULL;
    end->next->item = other;
    return true;
}

void distroy_item_list(list_t *list)
{
    list_t *temp = list;
    list_t *end = list;

    while (end) {
        end = temp->next;
        destroy_item(temp->item);
        free(temp->item);
        free(temp);
        temp = end;
    }
}

static list_t *set_all_item(void)
{
    char *path[] = {"./asset/config/soap.conf", "./asset/config/knife.conf",
                    NULL,
                    };
    list_t *ret = NULL;
    item_t *tmp;

    for (size_t i = 0; path[i]; i++) {
        tmp = item_load(path[i]);
        if (!tmp)
            return NULL;
        if (!add_one(&ret, tmp))
            return NULL;
    }
    return ret;
}

bool item_manage(list_t **list)
{
    *list = set_all_item();
    if (!(*list))
        return false;
    return true;
}