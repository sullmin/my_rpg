/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_rpg.h"

static int first_exec(game_t *game, bool *is_first_exec)
{
    *is_first_exec = false;
    if (kinem_start(&ISOW, &game->sound) != EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}

void isow_run(game_t *game)
{
    static bool is_first_exec = true;

    if (is_first_exec) {
        first_exec(game, &is_first_exec);
    }
    if (ISOW.kinem.start == true) {
        kinem_run(&ISOW, &game->sound);
    }
    ISOW.timer += TIME_MILLI(ISOW.clock);
    sfClock_restart(ISOW.clock);
    if (ISOW.timer >= ISOW.ms_loop) {
        while (ISOW.timer >= ISOW.ms_loop)
            ISOW.timer -= ISOW.ms_loop;
        player_movement(&ISOW, game);
    }
    map_display(&ISOW, &ISOW.map, game->w.window);
    object_display(&ISOW.prison, game->w.window);
    object_display(&ISOW.player, game->w.window);
}
