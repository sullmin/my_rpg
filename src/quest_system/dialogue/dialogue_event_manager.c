/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

bool dialogue_read_next_sentence(sys_quest_t *sysquest)
{
    list_str_t *dialogue = NULL;

    if (sysquest->dialogue_id == IDX_DIALOGUE_END)
        dialogue = sysquest->pnj_dialogue_end;
    else if (sysquest->dialogue_id == IDX_DIALOGUE_FAIL)
        dialogue = sysquest->pnj_dialogue_fail;
    else
        dialogue = sysquest->pnj_dialogue[sysquest->dialogue_id];
    sysquest->curr_sentence = my_str_list_read(dialogue);
    if (sysquest->curr_sentence == NULL) {
        return false;
    }
    return true;
}

int dialogue_event_manager(game_t *game, sfEvent *event)
{
    if (!game || game->sysquest.play_dialogue == false) {
        return EXIT_FAILURE;
    } else if (!event || event->type != sfEvtKeyReleased) {
        return EXIT_FAILURE;
    }
    if (dialogue_read_next_sentence(&game->sysquest) == false) {
        game->sysquest.play_dialogue = false;
    }
    return EXIT_SUCCESS;
}
