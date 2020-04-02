/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** slider
*/

#ifndef SLIDER_H_
#define SLIDER_H_

#include "slider_t.h"

slider_t *create_slider(sfVector2f position, float length);
int destroy_slider(slider_t *slider);
void display_slider(slider_t *slider, sfRenderWindow *window);
void set_slider_color(slider_t *slider, sfColor bar, sfColor button);
void set_slider_size(slider_t *slider);
void set_slider_position(slider_t *slider);
#endif /* !SLIDER_H_ */
