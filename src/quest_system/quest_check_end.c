/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T11:08:08+02:00 | Author: simon
*/

#include "my_rpg.h"

/*
    Check if there are some item_end in player's inventory.
    Called by "inventory_add"(item)

    This function call => quest_finish if true.
*/

extern const quest_t QUEST_ARRAY[];

int sysquest_check_end(game_t *game)
{
    for (size_t id = 0; id < NB_QUEST; id++) {
        if (QUEST.is_active[id] == false) {
            continue;
        }
        if (is_in_player_inv(&game->inventory, QUEST_ARRAY[id].ref_item_end)
                == true) {
            quest_finish(game, id);
        }
    }
    return EXIT_SUCCESS;
}
