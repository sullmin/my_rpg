/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** my_rpg
*/

#include "my_rpg.h"

static void manage_quest(game_t *game, item_t *item)
{
    if (QUEST.is_active[4] == true && !my_strcmp(item->id, "111")) {
        quest_finish(game, 4, true);
        sound_manager_play(&SOUND, SUCCESS);
        quest_enable(game, 5);
    }
}

bool get_loot(game_t *game)
{
    list_t *item_load = game->item_load;
    list_t *end = item_load;

    if (!end)
        return false;
    while (end && (PLAYER_INT.x != end->item->pos.x
            && PLAYER_INT.y != end->item->pos.y)) {
        end = end->next;
    }
    if (!end)
        return false;
    if (!add_item_in_player_inv(&game->inventory, end->item)) {
        return false;
    }
    manage_quest(game, end->item);
    sound_manager_play(&SOUND, CLOCHE);
    return true;
}
