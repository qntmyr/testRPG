/*
** EPITECH PROJECT, 2023
** moove_sprite.c
** File description:
** moov sprite
*/

#include "../../../include/rpg_extra.h"

int my_getnbr(char *str)
{
    int x = 0;
    int y = 0;
    int result = 1;
    if (str[0] == '-') {
        result = result * -1;
        x = 1;
    }

    for (; str[x] != '\0'; x++) {
        if (str[x] >= '0' && str[x] <= '9') {
            y = y * 10;
            y = y + (str[x] - '0');
        } else {
            return (84);
        }
    }
    return (result * y);
}

int init_stock2(suitcase_t *suit)
{
    for (; suit->var->map[suit->var->i][suit->var->k] > 47 && suit->var->map[suit->var->i][suit->var->k] < 58; suit->var->k++, suit->var->h++) {
        suit->var->tableau[suit->var->h] = suit->var->map[suit->var->i][suit->var->k];
    }
    return 0;
}

int init_stock(suitcase_t *suit)
{
    suit->var->q = 0;
    suit->var->h = 0;
    suit->var->k = 0;
    suit->var->tab = malloc(sizeof(int) * 50);
    suit->var->tableau = malloc(sizeof(char) * 50);
    for (suit->var->k = 2; suit->var->map[suit->var->i][suit->var->k] != '\0'; suit->var->k++) {
        for (; suit->var->map[suit->var->i][suit->var->k] < 48 ||
               suit->var->map[suit->var->i][suit->var->k] > 57; suit->var->k++);
        init_stock2(suit);
        suit->var->tableau[suit->var->h] = '\0';
        suit->var->tab[suit->var->q] = my_getnbr(suit->var->tableau);
        suit->var->q++;
        suit->var->h = 0;
    }
    suit->var->tab[suit->var->q] = '\0';
    return 0;
}


int stock_all(suitcase_t *suit)
{
    for (suit->var->i = 0; suit->var->map[suit->var->i] != NULL; suit->var->i++) {
        if (suit->var->map[suit->var->i][0] == 'V') {
            init_stock(suit);
            gen_coffre_vita(suit, suit->image->coffre2->sprite, (sfVector2f){(suit->var->tab[0]), (suit->var->tab[1])}, suit->var->tab[2]);
        }
    }
    for (suit->var->i = 0; suit->var->map[suit->var->i] != NULL; suit->var->i++) {
        if (suit->var->map[suit->var->i][0] == 'S') {
            init_stock(suit);
            gen_coffre_speed(suit, suit->image->coffre3->sprite, (sfVector2f){(suit->var->tab[0]), (suit->var->tab[1])}, suit->var->tab[2]);        }
    }
    for (suit->var->i = 0; suit->var->map[suit->var->i] != NULL; suit->var->i++) {
        if (suit->var->map[suit->var->i][0] == 'F') {
            init_stock(suit);
            gen_coffre_force(suit, suit->image->coffre->sprite, (sfVector2f){(suit->var->tab[0]), (suit->var->tab[1])}, suit->var->tab[2]);
        }
    }
    return 0;
}
