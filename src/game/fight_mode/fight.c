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
    if (*events == NULL)
        *events = create_fight_events(game);
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

static void update_event_size(key_event_t *key, sfInt64 speed)
{
    if (key->toggle) {
        if (key->size >= 0) {
            key->size += speed / 10000 * (key->increase ? 1 : -1);
            sfText_setCharacterSize(key->text, key->size);
        } else
            key->finish = true;
        if (key->rotation > 0) {
            sfText_setRotation(key->text, key->rotation);
            key->rotation += speed / 250;
        }
        if (key->size > KEYS_MAX_SIZE)
            key->increase = false;
    }
}

static void event_group_run(game_t *game, combination_t events, float ms)
{
    for (int i = 0; i < events.nbr_comb; i++) {
        update_event_size(&events.group[i], ms * game->wfight.speed);
        if (events.group[i].size > 0)
            sfRenderWindow_drawText(game->w.window, events.group[i].text, NULL);
    }
}

static void manage_keys_pressed(combination_t *events)
{
    bool all_pressed = true;

    for (int i = 0; i < events->nbr_comb; i++)
        if (events->group[i].toggle
        && !sfKeyboard_isKeyPressed(events->group[i].key)) {
            all_pressed = false;
            break;
        }
    if (all_pressed)
        for (int i = 0; i < events->nbr_comb && events->group[i].toggle; i++) {
            events->group[i].increase = false;
            events->group[i].rotation = 1;
        }
}

int fight_loop(game_t *game)
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