/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight mode header
*/

#ifndef H_FIGHT_MODE
#define H_FIGHT_MODE

#include "isow.h"
//#include "window_t.h"

#define KEY_TAB_SIZE 36
#define KEYS_MAX_SIZE 100

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

typedef struct fight_mode_s
{
    int actions;
    float interval;
    float speed;
    int comb;
} fight_mode_t;

typedef struct fight_run_s
{
    sfClock *inter_clock;
    sfClock *update;
    combination_t *events;
    window_t window;
    int win;
} fight_run_t;

int play_fight(window_t window, fight_mode_t mfight);
combination_t *create_fight_events(fight_mode_t *mfight, window_t window);
void destroy_events(fight_run_t *rfight, int actions);
void event_group_run(fight_mode_t *mfight, fight_run_t *rfight,
                    combination_t events, float ms);
void manage_keys_pressed(combination_t *events);

#endif