/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create fight events
*/

#include "my_rpg.h"

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

static int fill_keys(game_t *game, combination_t key_event)
{
    int group_input = rand() % KEY_TAB_SIZE;

    for (int i = 0; i < key_event.nbr_comb; i++) {
        key_event.group[i].toggle = false;
        key_event.group[i].finish = false;
        key_event.group[i].increase = true;
        key_event.group[i].rotation = 0;
        key_event.group[i].size = 0;
        key_event.group[i].key = key_tab[group_input].code;
        key_event.group[i].text = sfText_create();
        key_event.group[i].font
            = sfFont_createFromFile("./asset/fonts/ChunkfiveEx.ttf");
        if (key_event.group[i].text == NULL || key_event.group[i].font == NULL)
            return EXIT_ERROR;
        sfText_setString(key_event.group[i].text, key_tab[group_input].key);
        sfText_setFont(key_event.group[i].text, key_event.group[i].font);
        sfText_setPosition(key_event.group[i].text, (sfVector2f) {rand()
            % (game->w.width - KEYS_MAX_SIZE),
            rand() % (game->w.height - KEYS_MAX_SIZE)});
    }
    return EXIT_SUCCESS;
}

combination_t *create_fight_events(game_t *game)
{
    combination_t *events = malloc(sizeof(combination_t) * game->wfight.actions);   

    if (events == NULL)
        return NULL;
    for (int i = 0; i < game->wfight.actions; i++) {
        events[i].nbr_comb = rand() % game->wfight.comb + 1;
        events[i].group = malloc(sizeof(key_event_t) * events[i].nbr_comb + 1);
        if (events[i].group == NULL)
            return NULL;
        if (fill_keys(game, events[i]) == EXIT_ERROR)
            return NULL;
    }
    return events;
}

void destroy_events(combination_t **key_events, sfClock **inter_clock,
                    sfClock **update, int actions)
{
    sfClock_destroy(*inter_clock);
    *inter_clock = NULL;
    sfClock_destroy(*update);
    *update = NULL;
    for (int i = 0; i < actions; i++)
        for (int k = 0; k < (*key_events)[i].nbr_comb; k++) {
            sfText_destroy((*key_events)[i].group[k].text);
            sfFont_destroy((*key_events)[i].group[k].font);
        }
    *key_events = NULL;
}