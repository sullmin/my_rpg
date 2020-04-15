/*
** EPITECH PROJECT, 2020
** MUL_my_world_2020
** File description:
** main function
*/

#include "my_rpg.h"

int isow_run(game_t *game)
{
    ISOW.timer += TIME_MILLI(ISOW.clock);
    sfClock_restart(ISOW.clock);
    //action_manager(w);
    map_display(w, &ISOW.map);
    if (ISOW.timer >= ISOW.ms_loop) {
        while (ISOW.timer >= ISOW.ms_loop)
            ISOW.timer -= ISOW.ms_loop;

    }
    object_display(&ISOW.player, ISOW.window);
    return EXIT_SUCCESS;
}

/*
int run(int ac, char **av)
{
    window_t w;

    if (window_create(&w) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (ac == 2 && load_from_argv(av[1], &w) == EXIT_ERROR) {
        window_destroy(&w);
        return EXIT_FAILURE;
    }
    if (map_create(&w.map_water, w.map.height, w.map.width))
        return EXIT_FAILURE;
    main_loop(&w);
    auto_save(&w.map);
    window_destroy(&w);
    return w.exit_status;
}
*/
