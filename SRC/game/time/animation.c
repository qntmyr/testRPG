/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../../include/my_rpg.h"

void animation_character(suitcase_t *suit)
{
    sfIntRect rect = sfSprite_getTextureRect(suit->image->main_character->sprite);
    if (suit->var->check == Normal) rect.left = 0;
    if (suit->var->check == Haut) rect.top = 192;
    if (suit->var->check == Gauche) rect.top = 64;
    if (suit->var->check == Droite) rect.top = 128;
    if (suit->var->check == Bas) rect.top = 0;
    sfSprite_setTextureRect(suit->image->main_character->sprite, rect);
    sfSprite_setTextureRect(suit->image->main_character_red->sprite, rect);
    sfIntRect rect_pnj = sfSprite_getTextureRect(suit->image->pnj->sprite);
    rect_pnj.top = 0;
    sfSprite_setTextureRect(suit->image->pnj->sprite, rect_pnj);
}

void animation_pnj(suitcase_t *suit)
{
    sfIntRect rect_pnj = sfSprite_getTextureRect(suit->image->pnj->sprite);
    rect_pnj.top = 0;
    sfSprite_setTextureRect(suit->image->pnj->sprite, rect_pnj);
}

void change_rect(suitcase_t *suit)
{
    sfIntRect rect = sfSprite_getTextureRect(suit->image->main_character->sprite);
    if (rect.left >= 192) rect.left = 0;
    rect.left += 64;
    sfSprite_setTextureRect(suit->image->main_character->sprite, rect);
    sfSprite_setTextureRect(suit->image->main_character_red->sprite, rect);
}

void change_pnj(suitcase_t *suit)
{
    sfIntRect rect_pnj = sfSprite_getTextureRect(suit->image->pnj->sprite);
    if (rect_pnj.left >= 96) rect_pnj.left = 0;
    rect_pnj.left += 32;
    sfSprite_setTextureRect(suit->image->pnj->sprite, rect_pnj);
}

void scene_pnj(suitcase_t *suit)
{
    suit->var->delta2 = sfClock_restart(suit->sett->clock_pnj).microseconds / 1000000.0f;
    suit->var->time2 += suit->var->delta2;
    while (suit->var->time2 >= 0.25) {
        animation_pnj(suit);
        change_pnj(suit);
        suit->var->time2 -= 0.25;
    }
}