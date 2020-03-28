/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:28:02+01:00 | Author: simon
*/

#include "my_rpg.h"

static int create_renderwindow(game_t *game)
{
    bool err = false;
    sfVideoMode video_mode = {
        GET_VAR_NBR(game, "W_WIDTH", &err),
        GET_VAR_NBR(game, "W_HEIGHT", &err),
        GET_VAR_NBR(game, "W_BPP", &err)};
    char *w_name = GET_VAR(game, "W_NAME");
    int fps;

    if (err || !w_name)
        return EXIT_ERROR;
    game->w.window = sfRenderWindow_create(video_mode, w_name, sfClose, NULL);
    free(w_name);
    fps = GET_VAR_NBR(game, "W_FPS", &err);
    sfRenderWindow_setFramerateLimit(game->w.window, fps);
    if (err)
        return EXIT_ERROR;
    sfRenderWindow_setPosition(game->w.window, (sfVector2i){0, 0});
    return EXIT_SUCCESS;
}

static int struct_init(game_t *game)
{
    bool err = false;

    game->w.width = GET_VAR_NBR(game, "W_WIDTH", &err);
    game->w.height = GET_VAR_NBR(game, "W_HEIGHT", &err);
    if (err)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int window_create(game_t *game)
{
    if (struct_init(game) == EXIT_ERROR) {
        return my_puterror("window_create: strcut init ERROR\n", EXIT_ERROR);
    } else if (create_renderwindow(game) == EXIT_ERROR) {
        return my_puterror("window_create: renderwin ERROR\n", EXIT_ERROR);
    }
    return EXIT_SUCCESS;
}
