/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_xp_bar
*/

#include "my_rpg.h"

static int update_xp_txt(game_t *game)
{
    char *nbr_lvl = NULL;
    char *str = NULL;

    if (WMAIN->lvl == 0) {
        nbr_lvl = my_strdup("0");
    } else {
        nbr_lvl = my_putnbr_base_str(WMAIN->lvl, "0123456789");
    }
    if (nbr_lvl == NULL)
        return EXIT_ERROR;
    str = my_str_concat("LVL:", nbr_lvl);
    if (str == NULL)
        return EXIT_ERROR;
    free(nbr_lvl);
    sfText_setString(WMAIN->bar->text, str);
    free(str);
    return EXIT_SUCCESS;
}

int update_xp_bar(game_t *game)
{
    char *nbr_lvl = NULL;
    char *str = NULL;

    if (WMAIN->xp > 10) {
        WMAIN->lvl += WMAIN->xp / 10;
        WMAIN->xp = WMAIN->xp % 10;
    }
    if (progress_set_percentage(WMAIN->bar, 10 * WMAIN->xp) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}