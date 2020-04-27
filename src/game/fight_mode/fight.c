/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight mode
*/

#include "my_rpg.h"

static int init_variables(sfClock **inter_clock, sfClock **update,
                        combination_t **events, game_t *game)
{
    if (*inter_clock == NULL)
        *inter_clock = sfClock_create();
    if (*update == NULL)
        *update = sfClock_create();
    if (*events == NULL) {
        *events = create_fight_events(game);
        game->wfight.win = true;
    }
    if (*events == NULL || *update == NULL || *inter_clock == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static bool is_finish(game_t *game, combination_t *events)
{
    for (int i = 0; i < game->wfight.actions; i++)
        for (int k = 0; k < events[i].nbr_comb; k++)
            if (!events[i].group[k].finish)
                return false;
    return true;
}

static void spawn_events(game_t *game, combination_t events,
                        sfInt64 microseconds, int n)
{
    if (microseconds / 1000 > n * game->wfight.interval)
        for (int i = 0; i < events.nbr_comb; i++)
            events.group[i].toggle = true;
}

static int fight_loop(game_t *game)
{
    static sfClock *inter_clock = NULL;
    static sfClock *update = NULL;
    static combination_t *events = NULL;

    if (init_variables(&inter_clock, &update, &events, game) == EXIT_ERROR)
        return EXIT_ERROR;
    for (int i = 0; i < game->wfight.actions; i++) {
        spawn_events(game, events[i],
                    sfClock_getElapsedTime(inter_clock).microseconds, i);
        event_group_run(game, events[i],
            sfClock_getElapsedTime(update).microseconds);
        manage_keys_pressed(&events[i]);
    }
    sfClock_restart(update);
    if (is_finish(game, events))
        destroy_events(&events, &inter_clock, &update, game->wfight.actions);
    return EXIT_SUCCESS;
}

void fight_mode(game_t *game)
{
    if (fight_loop(game) == EXIT_ERROR)
        game->state = ERR;
}
