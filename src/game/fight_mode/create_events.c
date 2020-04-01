/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create fight events
*/

const int key_tab_size = 36;
event_input_t const key_tab[key_tab_size] = {
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

static int fill_keys(game_t *game, key_event_t *key_event, int cmd_nbr)
{
    int group_key = rand() % key_tab_size;

    for (int i = 0; i < cmd_nbr; i++) {
        key_event[i].toggle = false;
        key_event[i].finish = false;
        key_event[i].increase = true;
        key_event[i].rotation = false;
        key_event[i].size = 0;
        key_event[i].key = key_tab[group_key].code;
        key_event[i].text = sfText_create();
        key_event[i].font = sfFont_createFromFile("./asset/fonts/ChunkfiveEx.ttf");
        if (key_event[i].text == NULL || key_event[i].font == NULL)
            return EXIT_ERROR;
        sfText_setString(text, key_tab[group_key].key);
        sfText_setFont(text, font);
        sfText_setPosition(text, (sfVector2f) {10 + rand()
            % (game->w.width - 20), 10 + rand() % (game->w.height - 20)});
    }
    return EXIT_SUCCESS;
}

key_event_t **create_fight_events(game_t *game)
{
    key_event_t **events = malloc(sizeof(key_event_t *) * game->wfight.actions);   
    int cmd_nbr;

    if (events == NULL)
        return NULL;
    for (int i = 0; i < game->wfight.actions; i++) {
        cmd_nbr = rand() % game->wfight.comb;
        events[i] = malloc(sizeof(key_event_t) * cmd_nbr + 1);
        if (events[i] == NULL)
            return NULL;
        events[i][cmd_nbr] = 0;
        if (fill_keys(game, events[i], cmd_nbr) == EXIT_ERROR)
            return NULL;
    }
    return events;
}