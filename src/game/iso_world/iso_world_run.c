/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_rpg.h"

void isow_run(game_t *game)
{
    ISOW.timer += TIME_MILLI(ISOW.clock);
    sfClock_restart(ISOW.clock);
    map_display(&ISOW, &ISOW.map, game->w.window);
    if (ISOW.timer >= ISOW.ms_loop) {
        while (ISOW.timer >= ISOW.ms_loop)
            ISOW.timer -= ISOW.ms_loop;

    }
    object_display(&ISOW.prison, game->w.window);
    object_display(&ISOW.player, game->w.window);
}
