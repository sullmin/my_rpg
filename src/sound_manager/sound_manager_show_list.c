/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-25T18:46:50+01:00 | Author: simon
*/

#include "sound_manager.h"

void sound_manager_show_list(sound_manager_t *sm)
{
    char *filename;
    int idx = 0;

    if (!sm || !sm->sounds || !sm->file_list)
        return;
    my_printf("%s%s", BLUE_C, BOLD_T);
    my_putstr("{{ Sound Manager : loaded files }}\n");
    my_putstr(DEFAULT_T);
    do {
        filename = my_file_list_read(sm->file_list);
        if (filename) {
            my_printf("%s%s<SOUND FILE>:\t", GREEN_C, BOLD_T);
            my_printf("%s\t\t{OK} ===> [ID: %d]\n", filename, idx);
            my_putstr(DEFAULT_T);
            idx++;
        }
    } while (filename);
    my_putstr("\n");
}
