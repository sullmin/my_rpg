/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:32:14+01:00 | Author: simon
*/

#include "my_rpg.h"

extern FUNC_EXEC fct_exec[NB_GAME_STATE];

static void crossroads(game_t *game)
{
    if (game->state == QUIT || game->state == ERR) {
        return;
    }
    if (fct_exec[game->state] != NULL)
        fct_exec[game->state](game);
    if (game->sysquest.play_dialogue == true) {
        dialogue_display(game);
    }
}

static int run(game_t *game)
{
    sfRenderWindow_clear(game->w.window, sfBlack);
    crossroads(game);
    if (game->state == ERR)
        return EXIT_ERROR;
    display_player_gui(game);
    sfRenderWindow_display(game->w.window);
    return EXIT_SUCCESS;
}

int game_loop(game_t *game)
{
    sfEvent event;

    //quest_enable(game, 0); // DEBUG => quest system dialogue
    game->state = MAIN_MENU;
    while (sfRenderWindow_isOpen(game->w.window)) {
        while (sfRenderWindow_pollEvent(game->w.window, &event))
            call_event_manager(game, &event);
        if (run(game) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
