/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

list_t *make_list(item_t *first)
{
    list_t *start = malloc(sizeof(list_t));

    if (!start)
        return NULL;
    start->next = NULL;
    start->item = first;
    return start;
}

int add_one(list_t *my_list, item_t *other)
{
    list_t *end = my_list;

    while (end->next)
        end = end->next;
    end->next = malloc(sizeof(list_t));
    if (!end->next)
        return EXIT_ERROR;
    end->next->next = NULL;
    end->next->item = other;
    return EXIT_SUCCESS;
}

void distroy(list_t *list)
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