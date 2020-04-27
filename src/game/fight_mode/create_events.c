/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create fight events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fight.h"

const event_input_t key_tab[36] = {
    {sfKeyA, "A"},
    {sfKeyB, "B"},
    {sfKeyC, "C"},
    {sfKeyD, "D"},
    {sfKeyE, "E"},
    {sfKeyF, "F"},
    {sfKeyG, "G"},
    {sfKeyH, "H"},
    {sfKeyI, "I"},
    {sfKeyJ, "J"},
    {sfKeyK, "K"},
    {sfKeyL, "L"},
    {sfKeyM, "M"},
    {sfKeyN, "N"},
    {sfKeyO, "O"},
    {sfKeyP, "P"},
    {sfKeyQ, "Q"},
    {sfKeyR, "R"},
    {sfKeyS, "S"},
    {sfKeyT, "T"},
    {sfKeyU, "U"},
    {sfKeyV, "V"},
    {sfKeyW, "W"},
    {sfKeyX, "X"},
    {sfKeyY, "Y"},
    {sfKeyZ, "Z"},
    {sfKeyNum0, "0"},
    {sfKeyNum1, "1"},
    {sfKeyNum2, "2"},
    {sfKeyNum3, "3"},
    {sfKeyNum4, "4"},
    {sfKeyNum5, "5"},
    {sfKeyNum6, "6"},
    {sfKeyNum7, "7"},
    {sfKeyNum8, "8"},
    {sfKeyNum9, "9"}
};

static int set_key_values(key_event_t *key, event_input_t input)
{
    key->toggle = false;
    key->finish = false;
    key->increase = true;
    key->rotation = 0;
    key->size = 0;
    key->key = input.code;
    key->text = sfText_create();
    key->font = sfFont_createFromFile("./asset/font/ChunkfiveEx.ttf");
    if (key->text == NULL || key->font == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static void set_key_text(window_t window, key_event_t *key, event_input_t input,
                        sfColor color)
{
    sfText_setString(key->text, input.key);
    sfText_setFont(key->text, key->font);
    sfText_setColor(key->text, color);
    sfText_setPosition(key->text, (sfVector2f) {rand()
        % (window.width - KEYS_MAX_SIZE), rand() % (window.height - KEYS_MAX_SIZE)});
}

static int fill_keys(window_t window, combination_t key_evt)
{
    int group_input;
    sfColor color = sfColor_fromInteger(rand() % 0xffffffff);

    while (color.r < 50 && color.g < 50 && color.b < 50)
        color = sfColor_fromInteger(rand() % 0xffffffff);
    color.a = 255;
    for (int i = 0; i < key_evt.nbr_comb; i++) {
        group_input = rand() % KEY_TAB_SIZE;
        set_key_values(&key_evt.group[i], key_tab[group_input]);
        set_key_text(window, &key_evt.group[i], key_tab[group_input], color);
    }
    return EXIT_SUCCESS;
}

combination_t *create_fight_events(fight_mode_t *mfight, window_t window)
{
    combination_t *events = malloc(sizeof(combination_t) * mfight->actions);

    if (events == NULL)
        return NULL;
    for (int i = 0; i < mfight->actions; i++) {
        events[i].nbr_comb = rand() % mfight->comb + 1;
        events[i].group = malloc(sizeof(key_event_t) * events[i].nbr_comb + 1);
        if (events[i].group == NULL)
            return NULL;
        if (fill_keys(window, events[i]) == EXIT_ERROR)
            return NULL;
    }
    return events;
}

void destroy_events(fight_run_t *rfight, int actions)
{
    sfClock_destroy(rfight->inter_clock);
    rfight->inter_clock = NULL;
    sfClock_destroy(rfight->update);
    rfight->update = NULL;
    for (int i = 0; i < actions; i++)
        for (int k = 0; k < (rfight->events)[i].nbr_comb; k++) {
            sfText_destroy((rfight->events)[i].group[k].text);
            sfFont_destroy((rfight->events)[i].group[k].font);
        }
    rfight->events = NULL;
}
