/*
** EPITECH PROJECT, 2023
** fight
** File description:
** fight
*/

#include "../../../include/my_rpg.h"

void create_use_fight(suitcase_t *suit)
{
    // suit->fight->jauge = sfRectangleShape_create();
    // sfRectangleShape_setSize(suit->fight->jauge, (sfVector2f){20, 200});
    // sfRectangleShape_setPosition(suit->fight->jauge, (sfVector2f){500, 500});
    // sfRectangleShape_setFillColor(suit->fight->jauge, sfWhite);
}

void scene_fight(suitcase_t *suit)
{
    if (sfKeyboard_isKeyPressed(sfKeyT))
        suit->repo = GAME_SCENE;
    sfRenderWindow_setView(suit->sett->window, suit->fight->norm);
    sfRenderWindow_drawSprite(suit->sett->window, suit->fight->scene->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->fight->jauge->sprite, NULL);
    return;
}