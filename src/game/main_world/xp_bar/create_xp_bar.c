/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_xp_bar
*/

#include "my_rpg.h"

int set_color(game_t *game)
{
    int back = 0;
    int front = 0;
    bool err = 0;

    back = GET_VAR_NBR(game, "BACK_COLOR", &err);
    if (err)
        return EXIT_ERROR;
    front = GET_VAR_NBR(game, "FRONT_COLOR", &err);
    if (err)
        return EXIT_ERROR;
    progress_set_color_back(WMAIN->bar, sfColor_fromInteger(back));
    progress_set_color_front(WMAIN->bar, sfColor_fromInteger(front));
    return EXIT_SUCCESS;
}

int set_position_size(game_t *game)
{
    sfVector2f size = {0};
    sfVector2f position = {0};
    bool err = false;

    size.x = GET_VAR_NBR(game, "XP_SIZEX", &err);
    if (err)
        return EXIT_ERROR;
    size.y = GET_VAR_NBR(game, "XP_SIZEY", &err);
    if (err)
        return EXIT_ERROR;
    position.x = GET_VAR_NBR(game, "XP_POSX", &err);
    if (err)
        return EXIT_ERROR;
    position.y = GET_VAR_NBR(game, "XP_POSY", &err);
    if (progress_create(WMAIN->bar, size, position,  "LVL:") == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int create_xp_bar(game_t *game)
{
    WMAIN->bar = malloc(sizeof(progress_t));
    if (WMAIN->bar == NULL)
        return EXIT_ERROR;
    if (set_position_size(game) == EXIT_ERROR)
        return EXIT_ERROR;
    if (set_color(game) == EXIT_ERROR)
        return EXIT_ERROR;
    progress_set_percentage(WMAIN->bar, 0);
    WMAIN->xp = 0;
    WMAIN->lvl = 0;
    return EXIT_SUCCESS;
}
