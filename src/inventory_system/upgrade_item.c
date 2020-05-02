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

void level_up_item(game_t *game)
{
    size_t i;

    for (i = 0; i < INVENTORY.size; i++)
        if (INVENTORY.inventory[i] &&
            my_strcmp("000", INVENTORY.inventory[i]->id) == 0)
            break;
    if (i == INVENTORY.size) {
        move_item_in_inventory(game, "000");
        return;
    }
    uprage_item(INVENTORY.inventory[i]);
}