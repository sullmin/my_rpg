/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight mode header
*/

#ifndef H_FIGHT_MODE
#define H_FIGHT_MODE

#define KEY_TAB_SIZE 36

#define KEYS_MAX_SIZE 50

typedef struct event_input_s
{
    sfKeyCode code;
    char *key;
} event_input_t;

typedef struct key_event_s
{
    bool toggle;
    bool finish;
    bool increase;
    float rotation;
    int size;
    sfKeyCode key;
    sfText *text;
    sfFont *font;
} key_event_t;

typedef struct combination_s
{
    key_event_t *group;
    int nbr_comb;
} combination_t;

void fight_mode(game_t *game);
combination_t *create_fight_events(game_t *game);
void destroy_events(combination_t **key_events, sfClock **inter_clock,
                    sfClock **update, int actions);
void event_group_run(game_t *game, combination_t events, float ms);
void manage_keys_pressed(combination_t *events);

#endif