/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-gebril.cherier
** File description:
** set_xp
*/

#include "../../../include/rpg_extra.h"

void set_xp(suitcase_t *suit)
{
    char lvl[16];
    char *str = "lvl.";
    char *str2 = "Name";
    int_to_str(suit->var->lvl_up, lvl);
    float scale = 2 + suit->var->change_xp;
    float lightX = 0.81f + suit->var->change_light;
    float lightY = 0.62f + suit->var->change_light;
    if (scale >= 345) {
        suit->var->change_xp = 0;
        suit->var->lvl_up += 1;
        suit->var->change_light += 0.25f;
    }
    sfSprite_setScale(suit->image->black->sprite, (sfVector2f){lightX, lightY});
    create_text(str, (sfVector2f){1720, 960}, (sfVector2f) {0.7, 0.7}, suit);
    create_text(lvl, (sfVector2f){1790, 960}, (sfVector2f) {0.7, 0.7}, suit);
    create_text(str2, (sfVector2f){1520, 960}, (sfVector2f) {0.7, 0.7}, suit);
    create_rectangle(&suit->xp, (sfVector2f){1500, 995}, (sfVector2f){350, 20}, suit);
    create_rectangle2(&suit->xp, (sfVector2f){1503, 998}, (sfVector2f){scale, 17}, suit);
}

