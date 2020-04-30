/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main function
*/

#include "my_rpg.h"
#include <unistd.h>
#include <fcntl.h>

static unsigned int my_time(void)
{
    int read_size;
    unsigned int my_rand = 0;
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return 0;
    read_size = read(fd, &my_rand, sizeof(my_rand));
    if (read_size == -1)
        return 0;
    close(fd);
    return my_rand;
}

int main(int argc, char **argv)
{
    srand(my_time());
    if (argc > 1) {
        return usage(EXIT_SUCCESS, argv[0]);
    } else {
        return master();
    }
    return EXIT_SUCCESS;
}
