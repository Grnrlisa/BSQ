/*
** EPITECH PROJECT, 2021
** fs open
** File description:
** open file
*/

#include "my.h"

void display(char **map, int height, int width)
{
    for (int y = 1; y <= height; y++) {
        write(1, map[y], width);
        write(1, "\n", 1);
    }
}