/*
** EPITECH PROJECT, 2022
** xord_array
** File description:
** word_array
*/

#include "../include/rpg_extra.h"

int calc_l(char *str, int d, char delim)
{
    int i = d;
    for (; str[d] != delim && str[d] != '\0'; d++);
    return d - i;
}

char **my_str_to_word_array(char *str, char delim)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            count++;
    }
    count++;
    char **recieve = malloc(sizeof(char *) * (count + 1));
    int e;
    int d = 0;
    int i = 0;
    for (; i < count; i++) {
        recieve[i] = malloc(sizeof(char) * (calc_l(str, d, delim) + 1));
        for (e = 0; str[d] != delim && str[d] != '\0'; d++, e++) {
            recieve[i][e] = str[d];
        }
        recieve[i][e] = '\0';
        d++;
    }
    recieve[count] = NULL;
    return recieve;
}
