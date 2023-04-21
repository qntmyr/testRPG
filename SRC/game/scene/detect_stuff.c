/*
** EPITECH PROJECT, 2023
** scene_moov.c
** File description:
** scene moov
*/

#include "../../../include/rpg_extra.h"

void detect_on(suitcase_t *suit)
{
    suit->floatrect->bounds_botte = sfSprite_getGlobalBounds(suit->image->botte->sprite);
    suit->floatrect->bounds_lampe = sfSprite_getGlobalBounds(suit->image->lampe->sprite);
    suit->floatrect->bounds_main_character = sfSprite_getGlobalBounds(suit->image->main_character->sprite);
    if (sfFloatRect_intersects(&suit->floatrect->bounds_main_character, &suit->floatrect->bounds_botte, NULL)) {
        suit->var->speed_int += 40;
        suit->var->change = 1;
        suit->var->boo1 = 1;
        sfSprite_setScale(suit->image->botte->sprite, (sfVector2f){0.2f, 0.2f});
        sfSprite_setPosition(suit->image->secret_2->sprite, (sfVector2f){-100.f, -100.f});
        sfSprite_setPosition(suit->image->botte->sprite, (sfVector2f){76.f, 1007.f});
    }
    if (sfFloatRect_intersects(&suit->floatrect->bounds_main_character, &suit->floatrect->bounds_lampe, NULL)) {
        suit->var->boo = 1;
        sfSprite_setScale(suit->image->lampe->sprite, (sfVector2f){0.18f, 0.18f});
        sfSprite_setPosition(suit->image->secret_1->sprite, (sfVector2f){-100.f, -100.f});
        sfSprite_setPosition(suit->image->lampe->sprite, (sfVector2f){19.f, 1065.f});
        sfSprite_setRotation(suit->image->lampe->sprite, -90);
    }
}
