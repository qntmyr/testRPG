/*
** EPITECH PROJECT, 2023
** create_mob
** File description:
** create_mob
*/

#include "../include/my_rpg.h"

void draw_mobs(mob_t *list, suitcase_t *suit)
{
    mob_t *temp = list;
    while (temp) {
        if (temp->direction == 0) {
            if (temp->sens == 0) {
                temp->stock.x -= 0.1;
                if (temp->stock.x < temp->arrive.x)
                    temp->sens = 1;
            } else {
                temp->stock.x += 0.1;
                if (temp->stock.x > temp->depart.x)
                    temp->sens = 0;
            }
        } else {
            if (temp->sens == 0) {
                temp->stock.y -= 0.1;
                if (temp->stock.y < temp->arrive.y)
                    temp->sens = 1;
            } else {
                temp->stock.y += 0.1;
                if (temp->stock.y > temp->depart.y)
                    temp->sens = 0;
            }
        }
        sfSprite_setPosition(temp->mob->sprite, temp->stock);
        sfRenderWindow_drawSprite(suit->sett->window, temp->mob->sprite, NULL);
        temp = temp->next;
    }
}

void define_mob(suitcase_t *suit)
{
    suit->mob = malloc(sizeof(mob_t));
    suit->mob = NULL;
    for (int i = 0; suit->info_mobs[i] != NULL; i++) {
        char **tab = my_str_to_word_array(suit->info_mobs[i], ' ');
        mob_t *temp = malloc(sizeof(mob_t));
        temp->mob = create_sprite("assets/item/secret.png",
        (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])},
        (sfVector2f){0.1, 0.1}, 0);
        temp->stock = temp->depart;
        temp->vitesse = my_getnbr(tab[2]);
        temp->direction = my_getnbr(tab[6]);
        if (temp->direction == 0) {
            if (my_getnbr(tab[0]) >= my_getnbr(tab[4])) {
                temp->depart = (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])};
                temp->arrive = (sfVector2f){my_getnbr(tab[4]), my_getnbr(tab[5])};
            } else {
                temp->arrive = (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])};
                temp->depart = (sfVector2f){my_getnbr(tab[4]), my_getnbr(tab[5])};
            }
        } else {
            if (my_getnbr(tab[1]) >= my_getnbr(tab[5])) {
                temp->depart = (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])};
                temp->arrive = (sfVector2f){my_getnbr(tab[4]), my_getnbr(tab[5])};
            } else {
                temp->arrive = (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])};
                temp->depart = (sfVector2f){my_getnbr(tab[4]), my_getnbr(tab[5])};
            }
        }
        temp->sens = 0;
        temp->next = suit->mob;
        suit->mob = temp;
    }
}
