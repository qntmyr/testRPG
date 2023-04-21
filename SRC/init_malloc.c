/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my_rpg.h"


void init_malloc(suitcase_t *suit)
{
    suit->fight = malloc(sizeof(fight_t));
    suit->mob = malloc(sizeof(mob_t));
    suit->view = malloc(sizeof(view_t));
    suit->mouse = malloc(sizeof(mouse_t));
    suit->sett = malloc(sizeof(param_t));
    suit->image = malloc(sizeof(images_t));
    suit->floatrect = malloc(sizeof(floatrect_t));
    suit->var = malloc(sizeof(var_t));
}