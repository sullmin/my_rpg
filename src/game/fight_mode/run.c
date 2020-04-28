/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** run fight
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "fight.h"

static bool update_event_size(key_event_t *key, sfInt64 speed)
{
    if (key->toggle) {
        if (key->size >= 0) {
            key->size += speed / 10000 * (key->increase ? 1 : -1);
            sfText_setCharacterSize(key->text, key->size);
        } else {
            key->finish = true;
            if (key->rotation == 0)
                return true;
        }
        if (key->rotation > 0) {
            sfText_setRotation(key->text, key->rotation);
            key->rotation += speed / 250;
        }
        if (key->size > KEYS_MAX_SIZE)
            key->increase = false;
    }
    return false;
}

void event_group_run(fight_mode_t *mfight, fight_run_t *rfight,
                    combination_t events, float ms)
{
    for (int i = 0; i < events.nbr_comb; i++) {
        if (update_event_size(&events.group[i], ms * mfight->speed))
            rfight->win = false;
        if (events.group[i].size > 0)
            sfRenderWindow_drawText(rfight->window.window,
                                    events.group[i].text, NULL);
    }
}

void manage_keys_pressed(combination_t *events)
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