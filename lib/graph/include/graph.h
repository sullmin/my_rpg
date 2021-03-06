/*
** EPITECH PROJECT, 2019
** graph lib .h
** File description:
** all prototypes
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <SFML/Graphics.h>

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef sfVector2f vec;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
                    sfColor color);
void my_draw_rect(framebuffer_t *buffer, sfVector2f coords, sfVector2f size,
                    sfColor color);
void my_draw_line(framebuffer_t *framebuffer, sfVector2f point_a,
                    sfVector2f point_b, sfColor color);
void my_draw_rhombus(framebuffer_t *framebuffer, sfVector2f coord, int radius,
                    sfColor color);
void my_draw_circle(framebuffer_t *framebuffer, sfVector2f coord, int radius,
                    sfColor color);
void my_draw_batman(framebuffer_t *fb, sfVector2f co, int radius, sfColor c);
sfColor my_get_pixel_color(framebuffer_t *framebuffer, unsigned int x,
                    unsigned int y);
void fill_background(framebuffer_t *framebuffer, sfColor color);

#endif