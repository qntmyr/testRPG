/*
** EPITECH PROJECT, 2023
** moove_sprite.c
** File description:
** moov sprite
*/

#include "../../../include/rpg_extra.h"

char *read_map(suitcase_t *suit, int fd, char const *filepath)
{
    suit->unused = 0;
    struct stat sb;
    char *buff;
    fd = open(filepath, O_RDONLY);
    stat(filepath, &sb);
    buff = malloc(sizeof(char) * sb.st_size + 1);
    buff[sb.st_size] = '\0';
    read(fd, buff, sb.st_size);
    close(fd);
    return (buff);
}
