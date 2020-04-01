/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** fight mode header
*/

typedef struct fight_mode_s
{
    int actions;
    float interval;
    float speed;
    int comb;
} fight_mode_t;

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
    bool rotation;
    int size;
    sfKeyCode key;
    sfText *text;
    sfFont *font;
} key_event_t;