/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../../include/my_rpg.h"

void check_bool(suitcase_t *suit)
{
    if (suit->var->change_scene == 1 && suit->booleen == 0) {
        suit->view->position = (sfVector2f){100.0f, 78.0f};
        sfSprite_setPosition(suit->image->main_character->sprite, suit->view->position);
        sfSprite_setPosition(suit->image->main_character_red->sprite, suit->view->position);
        sfSprite_setPosition(suit->image->black->sprite, suit->view->position);
        init_hitboxes(suit, suit->originalHitboxes);
        suit->booleen = 1;
    }
    if (suit->var->change == 0) {
        sfRenderWindow_drawSprite(suit->sett->window, suit->image->main_character->sprite, NULL);
    }
    if (suit->var->change == 1) {
        sfRenderWindow_drawSprite(suit->sett->window, suit->image->main_character_red->sprite, NULL);
    }
    if (suit->var->boo1 == 0 && suit->booleen == 1) sfRenderWindow_drawSprite(suit->sett->window, suit->image->botte->sprite, NULL);
    if (suit->var->boo == 0) sfRenderWindow_drawSprite(suit->sett->window, suit->image->lampe->sprite, NULL);
    if (suit->booleen == 1)
        sfRenderWindow_drawSprite(suit->sett->window, suit->image->black->sprite, NULL);
}

void entry_s(suitcase_t *suit)
{
    create_circle(suit, &suit->var->cir, sfBlack, (sfVector2f){592.0f, 590.0f});
    sfFloatRect entre = sfCircleShape_getGlobalBounds(suit->var->cir);
    if (sfFloatRect_intersects(&suit->floatrect->bounds_main_character, &entre, NULL))
    suit->var->change_scene = 1;
}

void scene_game(suitcase_t *suit)
{
    sfRenderWindow_setView(suit->sett->window, suit->view->view);
    entry_s(suit);
    if (suit->var->change_scene == 0)
        sfRenderWindow_drawSprite(suit->sett->window, suit->image->tuto->sprite, NULL);
    if (suit->booleen == 1)
        sfRenderWindow_drawSprite(suit->sett->window, suit->view->map->sprite, NULL);
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->point->sprite, NULL);
    if (suit->booleen == 0) sfRenderWindow_drawSprite(suit->sett->window, suit->image->pnj->sprite, NULL);
    draw_mobs(suit->mob, suit); scene_moov(suit);
    moov_character(suit); check_bool(suit);
    sfRenderWindow_setView(suit->sett->window, suit->view->inv);
    draw_all_stuff(suit);
    stats_manager(suit);
    if (suit->var->boo1 == 1)
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->botte->sprite, NULL);
    if (suit->var->boo == 1)
    sfRenderWindow_drawSprite(suit->sett->window, suit->image->lampe->sprite, NULL);
    set_xp(suit);
    return;
}
