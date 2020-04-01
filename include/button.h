/*
** EPITECH PROJECT, 2019
** button.h
** File description:
** button.h
*/

#ifndef BUTTON_H
#define BUTTON_H

typedef struct my_button_shape_s {
    int toggle;
    char *name;
    sfVector2f pos;
    sfVector2f scale;
    sfText *text;
    sfFont *font;
    sfTexture **texture;
    sfClock *clock_start;
    sound_s sound;
    help_box_t help_box;
    bool is_pressed;
    bool is_activate;
} __attribute__((packed)) my_button_shape_t;

typedef struct sound_t
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_s;

typedef struct help_box_s
{
    sfFont *font;
    sfText *text;
    sfTexture *texture;
    sfSprite *sprite;
} help_box_t;

#endif