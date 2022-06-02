/*
** EPITECH PROJECT, 2021
** fs open
** File description:
** open file
*/

#include "bsq.h"
#include "my.h"

int main(int argc, char **argv)
{
    struct stat size;
    char *buff;
    int filedescriptor;

    stat(argv[1], &size);
    if (gest_errors_base(size.st_size) == 84)
        return (84);
    buff = malloc(sizeof(char) * (size.st_size + 1));
    if (argc == 2) {
        filedescriptor = open(argv[1], O_RDONLY);
        } else
        return (84);
    if (filedescriptor == -1)
        return (84);
    if (transform_map(filedescriptor, buff, size.st_size, argv[1]) == 84)
        return (84);
    free(buff);
    close(filedescriptor);
    return (0);
}