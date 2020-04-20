/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_rpg.h"

void isow_run(game_t *game)
{
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
