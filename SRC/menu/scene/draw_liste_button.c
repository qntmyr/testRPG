/*
** EPITECH PROJECT, 2023
** painto
** File description:
** draw_liste_button
*/

#include "../../../include/my_rpg.h"

void draw_liste_button(suitcase_t *suit)
{
    button_prop_t *it = suit->button;
    while (it != NULL) {
        sfRenderWindow_drawRectangleShape
            (suit->sett->window, it->shape, NULL);
        it = it->next;
    }
    return;
}

void update_but_scene(suitcase_t *suit)
{
    button_prop_t *it = suit->button;
    while (it != NULL) {
        if (button_update_scene(it, suit) == 3) {
            break;
        }
        it = it->next;
    }
    return;
}

void update_but(suitcase_t *suit)
{
    button_prop_t *it = suit->button;
    while (it != NULL) {
        if (button_update(it, suit) == 3) {
            suit->mouse->etat = 1;
            break;
        }
        it = it->next;
        suit->mouse->etat = 0;
    }
    return;
}
