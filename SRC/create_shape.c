/*
** EPITECH PROJECT, 2022
** button_menu
** File description:
** button_menu
*/

#include "../include/my_rpg.h"

void create_rectangle(sfRectangleShape **rectangle, sfVector2f position, sfVector2f size, suitcase_t *suit)
{
    sfRectangleShape_setPosition(*rectangle, position);
    sfRectangleShape_setSize(*rectangle, size);
    sfRectangleShape_setFillColor(*rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(*rectangle, 4);
    sfRectangleShape_setOutlineColor(*rectangle, sfColor_fromRGB(45, 59, 104));
    sfRenderWindow_drawRectangleShape(suit->sett->window, *rectangle, NULL);
}

void create_rectangle2(sfRectangleShape **rectangle, sfVector2f position, sfVector2f size, suitcase_t *suit)
{
    sfRectangleShape_setPosition(*rectangle, position);
    sfRectangleShape_setSize(*rectangle, size);
    sfRectangleShape_setFillColor(*rectangle, sfColor_fromRGB(156, 171, 216));
    // sfRectangleShape_setOutlineThickness(*rectangle, 2);
    // sfRectangleShape_setOutlineColor(*rectangle, sfColor_fromRGB(0, 100, 255));
    sfRenderWindow_drawRectangleShape(suit->sett->window, *rectangle, NULL);
}

void create_circle(suitcase_t *suit, sfCircleShape** button,
sfColor color, sfVector2f pos)
{
    float posX = pos.x - 3;
    float posY = pos.y - 2.5;
    sfCircleShape_setRadius(*button, 15);
    sfCircleShape_setFillColor(*button, color);
    sfCircleShape_setPosition(*button, (sfVector2f){posX, posY});
    sfCircleShape_setOutlineThickness(*button, 1);
    sfCircleShape_setOutlineColor(*button, sfBlack);
    // sfRenderWindow_drawCircleShape(suit->sett->window, *button, NULL);
}

void create_text(char* str, sfVector2f pos, sfVector2f size, suitcase_t *suit)
{
    sfFont* font = sfFont_createFromFile("assets/fonts/Gameplay.ttf");
    sfText* text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f) {pos.x, pos.y});
    sfText_setScale(text, size);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 2.5);
    sfRenderWindow_drawText(suit->sett->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}