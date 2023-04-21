/*
** EPITECH PROJECT, 2023
** painto
** File description:
** all_the_init
*/

#include "../include/my_rpg.h"

void insert_back_functions(suitcase_t *suit)
{
    suit->position = (sfVector2f){500.0f,
    (500.f)};
    insert_back(suit, (sfVector2f){(200.0f),
    (200.0f)}, &event_start, &scene_start);
    
}
