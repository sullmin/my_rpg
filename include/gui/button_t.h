/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_t
*/

#ifndef BUTTON_T_H_
#define BUTTON_T_H_

typedef struct button_s {
    int toggle;
    char *name;
    sfVector2f pos;
    sfVector2f scale;
    sfText *text;
    sfFont *font;
    sfTexture **texture;
    sound_t *sound;
    help_box_t *help_box;
    bool is_pressed;
    bool is_activate;
} button_t;

#endif /* !BUTTON_T_H_ */
