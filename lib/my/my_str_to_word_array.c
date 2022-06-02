/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** decoupe en mot uen suite
*/

#include "my.h"

int isa(char c)
{
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

int isnum(char c)
{
    return (c >= '0' && c <= '9');
}

int count_words(char const *str)
{
    int i = 0;
    int col = 0;

    for (; str[i] != '\0'; i++) {
        if (isa(str[i]) == 0 &&
            isnum(str[i]) == 0 &&
            (isa(str[i - 1]) == 1 ||
            isnum(str[i - 1]) == 1 || i == 0))
            col++;
    }
    if (isa(str[i - 1]) == 1 || isnum(str[i - 1]) == 1 || str[i] == '.')
        col++;
    return (col);
}

int word_len(char const *str, int i)
{
    int len = 0;

    for (; isa(str[i]) == 1 || isnum(str[i]) == 1 || str[i] == '.'; len++)
        i++;
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    char **dest;
    char *stock;
    int i = 0;
    int j = 0;
    int col = 0;

    dest = malloc(sizeof(char *) * (my_strlen(str) + 1));
    for (; str[i] != '\0' && col < count_words(str); i++) {
        stock = malloc(sizeof(char) * (word_len(str, i) + 1));
        for (; isa(str[i]) == 1 || isnum(str[i]) == 1 ||
            str[i] == '.'; j++, i++)
            stock[j] = str[i];
        if (j > 0) {
            stock[j] = '\0';
            dest[col] = stock;
            col++;
        }
        j = 0;
    }
    dest[col] = NULL;
    return (dest);
}
