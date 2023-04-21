/*
** EPITECH PROJECT, 2023
** moove_sprite.c
** File description:
** moov sprite
*/

#include "../../../include/rpg_extra.h"
#include "stdbool.h"

bool show_sprite = false;
bool has_been_pressed = false;

void int_to_str(int num, char* str)
{
    int i = 0;
    int sign = 0;
    if (num < 0) {
        sign = 1;
        num = -num;
    }
    do {
        str[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign) {
        str[i++] = '-';
    }
    str[i] = '\0';
    for (int j = sign; j < i / 2; j++) {
        char tmp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = tmp;
    }
}

void stats_manager(suitcase_t *suit)
{
    char vita[16];
    char force[16];
    char speed[16];
    int_to_str(suit->var->speed_int, speed);
    int_to_str(suit->var->vita_int, vita);
    int_to_str(suit->var->force_int, force);
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (!has_been_pressed) {
            if (show_sprite) {
                show_sprite = false;
            } else {
                show_sprite = true;
            }
            has_been_pressed = true;
        }
    }
    else {
        has_been_pressed = false;
    }

    if (show_sprite) {
        sfRenderWindow_drawSprite(suit->sett->window, suit->image->stats->sprite, NULL);
        create_text(vita, (sfVector2f){148.0f, 670.5f}, (sfVector2f){0.23 * 4, 0.23 * 4}, suit);
        create_text(force, (sfVector2f){148.0f, 748.f}, (sfVector2f){0.23 * 4, 0.23 * 4}, suit);
        create_text(speed, (sfVector2f){148.0f, 826.0f}, (sfVector2f){0.23 * 4, 0.23 * 4}, suit);
    }
    if (show_sprite == false) {
        char *str = "Press E to open stats menu";
        create_text(str, (sfVector2f){10.0f, 960.0f}, (sfVector2f){0.14 * 4, 0.14 * 4}, suit);
    }
}
