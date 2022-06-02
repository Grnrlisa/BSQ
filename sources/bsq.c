/*
** EPITECH PROJECT, 2021
** fs open
** File description:
** open file
*/

#include "my.h"
#include "bsq.h"

void printx(char **map, int square_y, int square_x, int the_big_square)
{
    int u = 0;

    while (u < the_big_square) {
        for (int i = 0; i < the_big_square; i++) {
            map[square_y + u][square_x + i] = 'x';
        }
        u++;
    }
}

int line_check(int width, int square_siz, char *line)
{
    for (int i = 0; i < square_siz; i++) {
        if (line[width + i] != '.')
            return (0);
    }
    return (1);
}

int square_sz(map_t *st_map, int h, int w, int square_size)
{
    int i = 0;

    while (i < square_size) {
        if (h + i >= st_map->height)
            return (0);
        else if (line_check(w, square_size, st_map->map[h + i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int get_big_sqr(map_t *st_map, int h, int w)
{
    int square_size = 1;

    while (square_sz(st_map, h, w, square_size) == 1)
        square_size++;

    return (square_size - 1);
}

void fd_big_sqr(map_t *st_map)
{
    int the_big_square = 0;
    int square_y = 0;
    int square_x = 0;
    int square_size = 0;

    for (int h = 0; h < st_map->height; h++) {
        for (int w = 0; w < st_map->width; w++) {
            square_size = get_big_sqr(st_map, h, w);
            if (square_size > the_big_square) {
                the_big_square = square_size;
                square_x = w;
                square_y = h;
            }
        }
    }
    printx(st_map->map, square_y, square_x, the_big_square);
    display(st_map->map, st_map->height, st_map->width);
}
