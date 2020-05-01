/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight mode
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "fight.h"

static int init_variables(fight_run_t *rfight, fight_mode_t *mfight)
{
    rfight->inter_clock = sfClock_create();
    if (rfight->inter_clock == NULL)
        return EXIT_ERROR;
    rfight->update = sfClock_create();
    if (rfight->update == NULL) {
        sfClock_destroy(rfight->inter_clock);
        return EXIT_ERROR;
    }
    rfight->events = create_fight_events(mfight, rfight->window);
    if (rfight->events == NULL) {
        sfClock_destroy(rfight->inter_clock);
        sfClock_destroy(rfight->update);
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

static bool is_finish(int actions, combination_t *events)
{
    for (int i = 0; i < actions; i++)
        for (int k = 0; k < events[i].nbr_comb; k++)
            if (!events[i].group[k].finish)
                return false;
    return true;
}

static void spawn_events(float interval, combination_t events,
                        sfInt64 microseconds, int n)
{
    if (microseconds / 1000 > n * interval)
        for (int i = 0; i < events.nbr_comb; i++)
            events.group[i].toggle = true;
}

static void fight_loop(fight_mode_t *mfight, fight_run_t *rfight,
sfSprite *background)
{
    while (!is_finish(mfight->actions, rfight->events)) {
        while (sfRenderWindow_pollEvent(rfight->window.window, &rfight->evt));
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            rfight->win = -1;
            break;
        }
        sfRenderWindow_clear(rfight->window.window, sfBlack);
        sfRenderWindow_drawSprite(rfight->window.window, background, NULL);
        for (int i = 0; i < mfight->actions; i++) {
            spawn_events(mfight->interval, rfight->events[i],
                sfClock_getElapsedTime(rfight->inter_clock).microseconds, i);
            event_group_run(mfight, rfight, rfight->events[i],
                sfClock_getElapsedTime(rfight->update).microseconds);
            manage_keys_pressed(&rfight->events[i]);
        }
        sfClock_restart(rfight->update);
        sfRenderWindow_display(rfight->window.window);
    }
    destroy_events(rfight, mfight->actions);
}

int play_fight(game_t *game, fight_mode_t mfight)
{
    fight_run_t rfight = {NULL, NULL, NULL, game->w, 1, {}};
    sfSprite *background = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(
        "./asset/sprite/fight/fight_bg.jpg", NULL);

    if (background == NULL || texture == NULL)
        return EXIT_ERROR;
    if (init_variables(&rfight, &mfight) == EXIT_ERROR)
        return EXIT_ERROR;
    sfSprite_setTexture(background, texture, sfTrue);
    fight_loop(&mfight, &rfight, background);
    sfSprite_destroy(background);
    sfTexture_destroy(texture);
    fight_post_end_action(game, rfight.win);
    return rfight.win;
}
