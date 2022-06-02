/*
** EPITECH PROJECT, 2021
** fs open
** File description:
** open file
*/

#include "my.h"
#include "bsq.h"

int gest_size_errors(size_t size, int width, int height, char **map)
{
    int i = ((size - 1) - height - my_strlen(map[0]));
    if ((width * height) != i)
        return (84);
    return (0);
}

int gest_errors_base(size_t size)
{
    if (size >= 4000000)
        return (84);
    if (size == 0)
        return (84);
    return (0);
}