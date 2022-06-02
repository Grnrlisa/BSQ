/*
** EPITECH PROJECT, 2021
** fs open
** File description:
** open file
*/

#include "bsq.h"
#include "my.h"

int w_map(char *av)
{
    int fd = open(av, O_RDONLY);
    char buff[1];
    int len_line = 0;
    int bool = 0;
    int reading = read(fd, buff, 1);

    while (reading != 0) {
        for (; bool == 0; reading = read(fd, buff, 1)) {
            if (buff[0] == '\n')
                bool = 1;
        }
        if (buff[0] == '\n')
            break;
        len_line++;
        reading = read(fd, buff, 1);
    }
    close(fd);
    return (len_line);
}

int h_map(char *av)
{
    int fd = open(av, O_RDONLY);
    char buff[1];
    char *nb = malloc(sizeof(char) * 5);
    int i = 0;
    int height;
    int reading = read(fd, buff, 1);

    while (reading != 0) {
        if (buff[0] >= 48 && buff[0] <= 57) {
            nb[i] = buff[0];
            i++;
            reading = read(fd, buff, 1);
        } else
            break;
    }
    close(fd);
    height = my_getnbr(nb);
    free(nb);
    return (height);
}