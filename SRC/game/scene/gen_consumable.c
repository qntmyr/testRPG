/*
** EPITECH PROJECT, 2023
** gen consu
** File description:
** consu
*/

#include "stdbool.h"
#include "../../../include/rpg_extra.h"

static bool* fKeyPressed = NULL;
static bool* statsBuffDisplayed = NULL;

void gen_coffre_text(suitcase_t *suit, sfVector2f coffre_pos)
{
    create_circle(suit, &suit->var->circle, sfTransparent, coffre_pos);
    suit->var->coffre_text.x = coffre_pos.x + 6;
    suit->var->coffre_text.y = coffre_pos.y - 0.5;
    suit->var->coffre_stats.x = coffre_pos.x - 6;
    suit->var->coffre_stats.y = coffre_pos.y - 8;
}

void gen_coffre_vita(suitcase_t *suit, sfSprite *sprite, sfVector2f pos, int index)
{
    if (fKeyPressed == NULL) {
        fKeyPressed = (bool*)malloc(50 * sizeof(bool));
        statsBuffDisplayed = (bool*)malloc(50 * sizeof(bool));
        for (int i = 0; i < 50; i++) {
            fKeyPressed[i] = false;
            statsBuffDisplayed[i] = false;
        }
    }

    suit->var->rect.top = 0;
    suit->var->rect.left = 0;
    suit->var->rect.width = 195;
    suit->var->rect.height = 150;
    char *str = "Press F";
    char *str2 = "   Vita stats applied\n\t\t\t   ( 0 - 5)";

    suit->floatrect->bounds_main_character = sfSprite_getGlobalBounds(suit->image->main_character->sprite);
    gen_coffre_text(suit, pos);
    sfFloatRect bound = sfCircleShape_getGlobalBounds(suit->var->circle);
    if (sfFloatRect_intersects(&suit->floatrect->bounds_main_character, &bound, NULL)) {
        if (sfKeyboard_isKeyPressed(sfKeyF) && !fKeyPressed[index - 1]) {
            suit->var->rect.left = 170;
            suit->var->rect.width = 195;
            fKeyPressed[index - 1] = true;
            suit->sett->clock1 = sfClock_create();
            srand(time(NULL));
            suit->var->vita_int += rand() % 6;
            suit->var->change_xp += 500;
        }
        if (fKeyPressed[index - 1] == false) {
            create_text(str, (sfVector2f){suit->var->coffre_text.x,
            suit->var->coffre_text.y}, (sfVector2f){0.1, 0.1}, suit);
        }
    }
    if (fKeyPressed[index - 1] == true && statsBuffDisplayed[index - 1] == false) {
        create_text(str2, (sfVector2f){suit->var->coffre_stats.x,
        suit->var->coffre_stats.y}, (sfVector2f){0.1,  0.1}, suit);
        suit->var->rect.left = 170;
        suit->var->rect.width = 195;
        if (suit->sett->clock1 && sfClock_getElapsedTime(suit->sett->clock1).microseconds >= 3000000) {
            statsBuffDisplayed[index - 1] = true;
            fKeyPressed[index - 1] = true;
            sfClock_destroy(suit->sett->clock1);
            suit->sett->clock1 = NULL;
        }
    }
    if (fKeyPressed[index - 1] == true) {
        suit->var->rect.left = 170;
        suit->var->rect.width = 195;
    }
    sfSprite_setTextureRect(sprite, suit->var->rect);
    sfSprite_setPosition(sprite, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawSprite(suit->sett->window, sprite, NULL);
}