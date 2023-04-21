/*
** EPITECH PROJECT, 2023
** painto
** File description:
** draw_liste_button
*/

#include "../../../include/my_rpg.h"

void clear_button(suitcase_t *suit)
{
    button_prop_t *it = suit->button;
    while (it != NULL) {
            it->state = None;
        it = it->next;
    }
    return;
}
