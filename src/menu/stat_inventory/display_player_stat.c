/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"
#include "display_stat.h"

static void display_str(sfRenderWindow *window, sfText *text, sfVector2f pos,
    char *str)
{
    if (!str)
        return;
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
}

static void display_name(sfRenderWindow *window, sfText *text, sfVector2f pos)
{
    char *name[] = {"Agility", "Strength", "Speed",
                    "Health", "Resistance", "IQ", NULL};

    for (size_t i = 0; name[i]; i++) {
        display_str(window, text, pos, name[i]);
        pos.y += INTER_LINE;
    }
}

static void display_value(sfRenderWindow *window, sfText *text, sfVector2f *pos,
    int nb)
{
    char *tmp = my_putnbr_base_str(nb, "0123456789");

    if (!tmp)
        return;
    display_str(window, text, *pos, tmp);
    free(tmp);
    pos->y += INTER_LINE;
}

void display_stat(sfRenderWindow *window, display_stat_t *info, stat_t *stat)
{
    sfVector2f pos = info->pos;
    sfText *text = sfText_create();

    if (!text)
        return;
    sfRenderWindow_drawSprite(window, info->sprite, NULL);
    pos.x += INTER_LINE * 8;
    sfText_setFont(text, info->font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    display_name(window, text, info->pos);
    display_value(window, text, &pos, stat->agility);
    display_value(window, text, &pos, stat->strength);
    display_value(window, text, &pos, stat->speed);
    display_value(window, text, &pos, stat->health);
    display_value(window, text, &pos, stat->resistance);
    display_value(window, text, &pos, stat->iq);
    sfText_destroy(text);
}
