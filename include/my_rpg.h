/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** my_paint
*/

#pragma once

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Cursor.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
    #include <unistd.h>
    #include "struct.h"
    #include "rpg_extra.h"
    #include <string.h>
    #include <sys/stat.h>
    #include <fcntl.h>

void scene(suitcase_t *suit);
void event(suitcase_t *suit);
int open_window(suitcase_t *suit);
void init(suitcase_t *suit);
void insert_back(suitcase_t *suit, sfVector2f size,
void (*func_ptr)(suitcase_t *), void (*func_ptr_scene)(suitcase_t *));
void helper(void);
void insert_back_functions(suitcase_t *suit);
void draw_liste_button(suitcase_t *suit);
void update_but_scene(suitcase_t *suit);
void update_but(suitcase_t *suit);
void inite_sprites_menu(suitcase_t *suit);
sprite_t *create_sprite(char *path,
sfVector2f pos, sfVector2f scale, int);
void clear_button(suitcase_t *suit);
int button_style(suitcase_t *suit, button_prop_t *button);
void button_set_color(button_prop_t *button, sfColor color);
int button_update(button_prop_t *button, suitcase_t *suit);
int button_update_scene(button_prop_t *button, suitcase_t *suit);
void button_destroy(button_prop_t *button);
button_prop_t *button_create(sfVector2f pos_sprite, sfVector2f size,
void (*func_ptr)(suitcase_t *), void (*func_ptr_scene)(suitcase_t *));
void scene_menu(suitcase_t *suit);
void event_menu(suitcase_t *suit);
void init_malloc(suitcase_t *suit);

void event_game(suitcase_t *suit);
void scene_game(suitcase_t *suit);
void time_menu(suitcase_t *suit);
void time_game(suitcase_t *suit);
void scene_start(suitcase_t *suit);
void event_start(suitcase_t *suit);
void event_fight(suitcase_t *suit);
void time_fight(suitcase_t *suit);
void scene_fight(suitcase_t *suit);
void create_use_fight(suitcase_t *suit);
