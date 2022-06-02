/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lisa.garnier
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stddef.h>

    typedef struct map
    {
        int width;
        int height;
        char **map;
    } map_t;

    int w_map(char *av);
    int h_map(char *av);
    int transform_map(int fd, char *buff, size_t size, char *file);
    void fd_big_sqr(map_t *st_map);
    void display(char **map, int height, int width);
    int gest_size_errors(size_t size, int width, int height, char **map);
    int gest_errors_base(size_t size);

#endif/* !BSQ_H_ */
