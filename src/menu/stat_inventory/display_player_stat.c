/*
** EPITECH PROJECT, 2019
** myrpg
** File description:
** myrpg
*/

#include "my_rpg.h"
#include "display_stat.h"

static void display_str(sfRenderWindow *window, sfText *text, sfVector2f *pos,
    char *str)
{
    if (!str)
        return;
    sfText_setString(text, str);
    sfText_setPosition(text, *pos);
    sfRenderWindow_drawText(window, text, NULL);
    pos->y += INTER_LINE;
}

static void display_name(sfRenderWindow *window, sfText *text, sfVector2f pos,
    size_t start)
{
    char *name[] = {"Name", "Description", "Agility", "Strength", "Speed",
                    "Health", "Resistance", "IQ", NULL};

    for (size_t i = start; name[i]; i++) {
        display_str(window, text, &pos, name[i]);
    }
}

static void display_value(sfRenderWindow *window, sfText *text, sfVector2f *pos,
    int nb)
{
    char *tmp = my_putnbr_base_str(nb, "0123456789");

    if (!tmp)
        return;
    if (tmp[0])
        display_str(window, text, pos, tmp);
    else display_str(window, text, pos, "0");
    free(tmp);
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
    display_name(window, text, info->pos, 2);
    display_value(window, text, &pos, stat->agility);
    display_value(window, text, &pos, stat->strength);
    display_value(window, text, &pos, stat->speed);
    display_value(window, text, &pos, stat->health);
    display_value(window, text, &pos, stat->resistance);
    display_value(window, text, &pos, stat->iq);
    sfText_destroy(text);
}

void compare_item(sfRenderWindow *win, display_stat_t *info, item_t *item)
{
    sfVector2f pos = (sfVector2f) {100, 100};
    sfText *txt = sfText_create();

    if (!txt)
        return;
    sfText_setFont(txt, info->font);
    sfText_setCharacterSize(txt, 35);
    sfText_setColor(txt, sfWhite);
    display_name(win, txt, pos, 0);
    pos.x += INTER_LINE * 8;
    display_str(win, txt, &pos, item->name);
    display_str(win, txt, &pos, item->description);
    display_value(win, txt, &pos, item->stats.agility);
    display_value(win, txt, &pos, item->stats.strength);
    display_value(win, txt, &pos, item->stats.speed);
    display_value(win, txt, &pos, item->stats.health);
    display_value(win, txt, &pos, item->stats.resistance);
    display_value(win, txt, &pos, item->stats.iq);
    sfText_destroy(txt);
}