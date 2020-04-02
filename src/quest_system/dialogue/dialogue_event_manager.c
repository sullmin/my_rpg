/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-31T09:26:46+02:00 | Author: simon
*/

#include "my_rpg.h"

int dialogue_event_manager(game_t *game, sfEvent *event)
{
    sys_quest_t *sysquest = &game->sysquest;

    if (!game || game->sysquest.play_dialogue == false) {
        return EXIT_FAILURE;
    } else if (!event || event->type != sfEvtKeyReleased) {
        return EXIT_FAILURE;
    }
    

}
