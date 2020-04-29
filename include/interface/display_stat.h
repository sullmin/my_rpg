/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#ifndef DISPLAY_STAT_H_
#define DISPLAY_STAT_H_

#include <SFML/Graphics.h>
#include "config_manager.h"
#include "stat_t.h"

typedef struct display_stat_s {
    sfVector2f pos;
    sfFont *font;
    sfSprite *sprite;
    sfTexture *texture;
    bool display_it;
    sfClock *clock;
} display_stat_t;

#define INTER_LINE 50

void display_stat(sfRenderWindow *window, display_stat_t *info, stat_t *stat);
bool init_display_stat(display_stat_t *info, env_t *env);
void destroy_display_stat(display_stat_t *info);

#endif