/*
** EPITECH PROJECT, 2023
** moove_sprite.c
** File description:
** moov sprite
*/

#include "../../../include/rpg_extra.h"

void haut(sfSprite *sprite, float vitesse, suitcase_t *suit, sfTime delta_time)
{
    suit->var->check = Haut;
    suit->view->pix = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x + 8)), (int)((suit->view->position.y - 13)));
    suit->view->pix1 = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x - 8)), (int)((suit->view->position.y - 13)));
    if (suit->view->pix.r + suit->view->pix.g + suit->view->pix.b > 0 && suit->view->pix1.r + suit->view->pix1.g + suit->view->pix1.b > 0) {
        suit->view->position.y -= vitesse * suit->var->vitesse_max * sfTime_asSeconds(delta_time);
    }
    sfSprite_setPosition(sprite, suit->view->position);
}


void bas(sfSprite *sprite, float vitesse, suitcase_t *suit, sfTime delta_time)
{
    suit->var->check = Bas;
    suit->view->pix = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x - 8)), (int)((suit->view->position.y + 18)));
    suit->view->pix1 = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x + 8)), (int)((suit->view->position.y + 18)));
    if (suit->view->pix.r + suit->view->pix.g + suit->view->pix.b > 0 && suit->view->pix1.r + suit->view->pix1.g + suit->view->pix1.b > 0) {
        suit->view->position.y += vitesse * suit->var->vitesse_max * sfTime_asSeconds(delta_time);
    }
    sfSprite_setPosition(sprite, suit->view->position);
}

void gauche(sfSprite *sprite, float vitesse, suitcase_t *suit, sfTime delta_time)
{
    suit->var->check = Gauche;
    suit->view->pix = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x - 11)), (int)((suit->view->position.y - 10)));
    suit->view->pix1 = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x - 11)), (int)((suit->view->position.y + 10)));
    if (suit->view->pix.r + suit->view->pix.g + suit->view->pix.b > 0 && suit->view->pix1.r + suit->view->pix1.g + suit->view->pix1.b > 0) {
        suit->view->position.x -= vitesse * suit->var->vitesse_max * sfTime_asSeconds(delta_time);
    }
    sfSprite_setPosition(sprite, suit->view->position);
}

void droite(sfSprite *sprite, float vitesse, suitcase_t *suit, sfTime delta_time)
{
    suit->var->check = Droite;
    suit->view->pix = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x + 11)), (int)((suit->view->position.y - 10)));
    suit->view->pix1 = sfImage_getPixel(suit->view->hitboxes, (int)((suit->view->position.x + 11)), (int)((suit->view->position.y + 10)));
    if (suit->view->pix.r + suit->view->pix.g + suit->view->pix.b > 0 && suit->view->pix1.r + suit->view->pix1.g + suit->view->pix1.b > 0) {
        suit->view->position.x += vitesse * suit->var->vitesse_max * sfTime_asSeconds(delta_time);
    }
    sfSprite_setPosition(sprite, suit->view->position);
}

void deplacer_sprite(sfSprite *sprite, float vitesse, suitcase_t *suit, sfTime delta_time)
{
    suit->var->vitesse_max = (10 + suit->var->speed_int) / 3.15;
    suit->var->check = Normal;
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ)) {
        haut(sprite, vitesse, suit, delta_time);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS)) {
        bas(sprite, vitesse, suit, delta_time);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ)) {
        gauche(sprite, vitesse, suit, delta_time);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD)) {
        droite(sprite, vitesse, suit, delta_time);
    }
    sfView_setCenter(suit->view->view, suit->view->position);
    sfSprite_setOrigin(suit->image->black->sprite, (sfVector2f){310.f, 225.f});
}