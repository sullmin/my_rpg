/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particles header
*/

#ifndef H_PARTICLES
#define H_PARTICLES

#include <SFML/Graphics.h>
#include "window_t.h"
#include "graph.h"

#define EXIT_ERROR 84
#define MAX_ID 2
#define RAND(min, max) min + rand() % (max - min + (min < 0))
#define SAND(i) pack->tpe_part.sand[i]
#define JMP_PIX(i) pack->tpe_part.jump_pixels[i]

extern const int jmpix_max_par;
extern const int sand_max_par;

typedef struct jump_pixels_s
{
    sfVector2f coord;
    float size;
    sfColor color;
} jump_pixels_t;

typedef struct sand_s
{
    sfVector2f coord;
    sfColor color;
    float angle;
    float speed;
    float size;
} sand_t;

typedef union tpe_part_s
{
    jump_pixels_t *jump_pixels;
    sand_t *sand;
} tpe_part_t;

typedef struct particles_pack_s
{
    int id;
    tpe_part_t tpe_part;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    framebuffer_t *framebuffer;
} particles_pack_t;

typedef int (* const CREATE_FUNC_ID)(particles_pack_t *pack,
                    sfColor color, float value);
typedef int (* const DRAW_FUNC_ID)(particles_pack_t *pack);
typedef void (* const DESTROY_FUNC_ID)(tpe_part_t tpe_part);
typedef void (* const SET_POS_FUNC_ID)(particles_pack_t *pack,
                                            sfVector2f pos, int radius);

particles_pack_t *create_particles(window_t window, int const id,
                                sfColor color, float value);
int draw_particles(particles_pack_t *pack);
void destroy_particles(particles_pack_t *pack);
void set_particles_pos(particles_pack_t *pack, sfVector2f pos, int radius);
void update_particles(particles_pack_t *pack, window_t win);

int create_jump_pixels(particles_pack_t *pack, sfColor color, float size);
void destroy_jump_pixels(tpe_part_t tpe_part);
void set_pos_jump_pixels(particles_pack_t *pack, sfVector2f coord, int radius);
int draw_jump_pixels(particles_pack_t *pack);

int create_sand(particles_pack_t *pack, sfColor color, float speed);
int draw_sand(particles_pack_t *pack);
void destroy_sand(tpe_part_t tpe_part);

#endif