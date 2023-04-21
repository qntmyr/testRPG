/*
** EPITECH PROJECT, 2023
** scene_moov.c
** File description:
** scene moov
*/

#include "../../../include/rpg_extra.h"

void moov_character(suitcase_t *suit)
{
    sfTime delta_time = sfClock_getElapsedTime(suit->sett->clock2);
    sfClock_restart(suit->sett->clock2);
    deplacer_sprite(suit->image->main_character->sprite, 10, suit, delta_time);
    deplacer_sprite(suit->image->main_character_red->sprite, 0, suit, delta_time);
    deplacer_sprite(suit->image->black->sprite, 0, suit, delta_time);
}

void scene_moov(suitcase_t *suit)
{
    detect_on(suit);
    scene_pnj(suit);
    suit->var->delta = sfClock_restart(suit->sett->clock3).microseconds / 1000000.0f;
    suit->var->time += suit->var->delta;
    while (suit->var->time >= 0.135) {
        animation_character(suit);
        // change_pnj(suit);
        if (suit->var->check != Normal) {
            change_rect(suit);
        }
        suit->var->time -= 0.135;
    }
    if (suit->var->change_scene == 1)
        stock_all(suit);
}
