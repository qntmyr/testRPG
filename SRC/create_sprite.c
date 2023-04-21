/*
** EPITECH PROJECT, 2022
** button_menu
** File description:
** button_menu
*/

#include "../include/my_rpg.h"

sprite_t *create_sprite(char *path,
sfVector2f pos, sfVector2f scale, int boolo)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->scale.x = (scale.x);
    sprite->scale.y = (scale.y);
    sprite->pos_sprite.x = (pos.x);
    sprite->pos_sprite.y = (pos.y);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setPosition(sprite->sprite, sprite->pos_sprite);
    if (boolo == 1)
        sfSprite_setOrigin(sprite->sprite, (sfVector2f){32, 32});
    return (sprite);
}

void init_var(suitcase_t *suit)
{
    suit->var->time = 0;
    suit->var->lvl_up = 1;
    suit->var->change_scene = 0;
    suit->var->change_light = 0;
    suit->sett->clock1 = NULL;
    suit->sett->clock2 = sfClock_create();
    suit->sett->clock3 = sfClock_create();
    suit->sett->clock_pnj = sfClock_create();
    suit->var->speed_int = 10;
    suit->var->force_int = 10;
    suit->var->vita_int = 10;
    suit->sett->clock = sfClock_create();
    suit->var->change = 0;
    suit->var->change_xp = 0;
    suit->var->boo = 0;
    suit->var->boo1 = 0;
}

void inite_sprites_menu(suitcase_t *suit)
{
    suit->var->circle = sfCircleShape_create();
    suit->var->cir = sfCircleShape_create();
    suit->xp = sfRectangleShape_create();
    suit->xp2 = sfRectangleShape_create();
    float secretBasePosX = -5.f;
    float secretPosY = 1000.0f;
    float secretSizeX = 0.025f * 4;
    float secretSizeY = 0.025f * 4;
    sfIntRect rect = {0, 0, 64, 64};
    sfIntRect rect_pnj = {0, 0, 32, 32};
    suit->image->main_character = create_sprite("assets/animation_character/m_characters.png", (sfVector2f){suit->view->position.x, suit->view->position.y}, (sfVector2f){0.4125, 0.4325}, 1);
    sfSprite_setTextureRect(suit->image->main_character->sprite, rect);
    suit->image->main_character_red = create_sprite("assets/animation_character/m_characters_red.png", (sfVector2f){suit->view->position.x, suit->view->position.y}, (sfVector2f){0.4125, 0.4325}, 1);
    sfSprite_setTextureRect(suit->image->main_character_red->sprite, rect);
    suit->image->black = create_sprite("assets/item/darkness.png", (sfVector2f){suit->view->position.x, suit->view->position.y}, (sfVector2f){0.81f, 0.62f}, 1);
    sfSprite_setOrigin(suit->image->black->sprite, (sfVector2f){310.f, 225.f});
    sfSprite_setColor(suit->image->black->sprite, sfColor_fromRGB(0, 0, 0));
    suit->image->coffre = create_sprite("assets/item/coffre_force.png", (sfVector2f){0.f, 0.f}, (sfVector2f){0.150f, 0.150f}, 0);
    suit->image->coffre2 = create_sprite("assets/item/coffre_vita.png", (sfVector2f){0.f, 0.f}, (sfVector2f){0.150f, 0.150f}, 0);
    suit->image->coffre3 = create_sprite("assets/item/coffre_speed.png", (sfVector2f){0.f, 0.f}, (sfVector2f){0.150f, 0.150f}, 0);
    suit->image->botte = create_sprite("assets/item/botte.png", (sfVector2f){230.0f, 325.0f}, (sfVector2f){0.05f, 0.05f}, 0);
    suit->image->secret_1 = create_sprite("assets/item/secret.png", (sfVector2f){secretBasePosX, secretPosY}, (sfVector2f){secretSizeX, secretSizeY}, 0);
    suit->image->secret_2 = create_sprite("assets/item/secret.png", (sfVector2f){secretBasePosX + 68.0f, secretPosY}, (sfVector2f){secretSizeX, secretSizeY}, 0);
    suit->image->secret_3 = create_sprite("assets/item/secret.png", (sfVector2f){secretBasePosX + (136.0f), secretPosY}, (sfVector2f){secretSizeX, secretSizeY}, 0);
    suit->image->secret_4 = create_sprite("assets/item/secret.png", (sfVector2f){secretBasePosX + (204.0f), secretPosY}, (sfVector2f){secretSizeX, secretSizeY}, 0);
    suit->image->secret_5 = create_sprite("assets/item/secret.png", (sfVector2f){secretBasePosX + (272.0f), secretPosY}, (sfVector2f){secretSizeX, secretSizeY}, 0);
    suit->image->secret_6 = create_sprite("assets/item/secret.png", (sfVector2f){secretBasePosX + 339.5f, secretPosY}, (sfVector2f){secretSizeX, secretSizeY}, 0);
    suit->image->lampe = create_sprite("assets/item/flashlight.png", (sfVector2f){400.0f, 610.0f}, (sfVector2f){0.0475f, 0.0475f}, 0);
    suit->image->inventory = create_sprite("assets/inventory/inventory.png", (sfVector2f){1.0f, 987.0f}, (sfVector2f){0.1075f * 4, 0.1075f * 4}, 0);
    suit->image->stats = create_sprite("assets/inventory/stats.png", (sfVector2f){0.0f, 600.0f}, (sfVector2f){0.225f * 4, 0.225f * 4}, 0);
    suit->fight->scene = create_sprite("assets/map/maze_fight.jpg", (sfVector2f){0, 0}, (sfVector2f){1, 1}, 0);
    suit->fight->jauge = create_sprite("assets/map/jauge.png", (sfVector2f){200, 600}, (sfVector2f){1, 1}, 0);
    suit->image->pnj = create_sprite("assets/animation/pnj.png", (sfVector2f){500.f, 530.f}, (sfVector2f){0.9f, 0.9f}, 0);
    suit->image->point = create_sprite("assets/item/point.png", (sfVector2f){515.f, 522.f}, (sfVector2f){0.025f, 0.025f}, 0);
    sfSprite_setTextureRect(suit->image->pnj->sprite, rect_pnj);
    return;
}

