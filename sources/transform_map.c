/*
** EPITECH PROJECT, 2021
** fs open
** File description:
** open file
*/

#include "my.h"
#include "bsq.h"

static void init_st_map(map_t *st_map, int height, int width, char **map)
{
    st_map->height = height;
    st_map->width = width;
    st_map->map = map;
}

int transform_map(int fd, char *buff, size_t size, char *file)
{
    int height = h_map(file);
    int width = w_map(file);
    char **darray = NULL;
    map_t st_map;

    read(fd, buff, size);
    buff[size] = '\0';
    darray = my_str_to_word_array(buff);
    if (gest_size_errors(size, width, height, darray) == 84)
        return (84);
    init_st_map(&st_map, height, width, darray);
    fd_big_sqr(&st_map);
    return (0);
}