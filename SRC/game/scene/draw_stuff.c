/*
** EPITECH PROJECT, 2023
** moove_sprite.c
** File description:
** moov sprite
*/

#include "../../../include/rpg_extra.h"

void draw_all_stuff(suitcase_t *suit)
{
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->inventory->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->secret_1->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->secret_2->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->secret_3->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->secret_4->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->secret_5->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->secret_6->sprite, NULL);
}