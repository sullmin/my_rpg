/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "inventory_system.h"

static void upgrade_stat(int *val)
{
    int get_prob = *val * 10;
    int nb = rand() % 101;

    if (get_prob == 0)
        get_prob++;
    if (nb < get_prob)
        *val += 1;
}

static void uprage_item(item_t *item)
{
    upgrade_stat(&item->stats.resistance);
    upgrade_stat(&item->stats.strength);
    upgrade_stat(&item->stats.agility);
    upgrade_stat(&item->stats.health);
    upgrade_stat(&item->stats.speed);
    upgrade_stat(&item->stats.iq);
}

void level_up(game_t *game)
{
    list_t *end = game->item_load;

    while (end && my_strcmp("000", end->item->id) != 0)
        end = end->next;
    if (!end) {
        if (move_item_in_inventory(game, "000"))
            level_up(game);
        else
            return;
    }
    uprage_item(end->item);
}