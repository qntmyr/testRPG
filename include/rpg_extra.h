/*
** EPITECH PROJECT, 2023
** rpg_extra.c
** File description:
** rpg_extra
*/

#pragma once

#include "my_rpg.h"

void scene_moov(suitcase_t *suit);
void deplacer_sprite(sfSprite *sprite, float vitesse, suitcase_t *suit, sfTime delta_time);
void create_text(char* str, sfVector2f pos, sfVector2f size, suitcase_t *suit);
void stats_manager(suitcase_t *suit);
void draw_all_stuff(suitcase_t *suit);
void init_var(suitcase_t *suit);
void moov_character(suitcase_t *suit);
void detect_on(suitcase_t *suit);
void gen_coffre_vita(suitcase_t *suit, sfSprite *sprite, sfVector2f pos, int index);
void gen_coffre_force(suitcase_t *suit, sfSprite *sprite, sfVector2f pos, int index);
void gen_coffre_speed(suitcase_t *suit, sfSprite *sprite, sfVector2f pos, int index);
void gen_coffre_text(suitcase_t *suit, sfVector2f pos);
char *read_map(suitcase_t *suit, int fd, char const *filepath);
char **my_str_to_word_array(char *buff, char delim);
int init_stock(suitcase_t *suit);
int init_stock2(suitcase_t *suit);
int stock_all(suitcase_t *suit);
void create_circle(suitcase_t *suit, sfCircleShape** button,
sfColor color, sfVector2f pos);
void define_mob(suitcase_t *suit);
int my_getnbr(char *str);
void draw_mobs(mob_t *list, suitcase_t *suit);
void create_rectangle(sfRectangleShape **rectangle, sfVector2f position, sfVector2f size, suitcase_t *suit);
void create_rectangle2(sfRectangleShape **rectangle, sfVector2f position, sfVector2f size, suitcase_t *suit);
void create_circle(suitcase_t *suit, sfCircleShape** button,
sfColor color, sfVector2f pos);
void change_rect(suitcase_t *suit);
void animation_pnj(suitcase_t *suit);
void scene_pnj(suitcase_t *suit);
void change_pnj(suitcase_t *suit);
void animation_character(suitcase_t *suit);
void int_to_str(int num, char* str);
void set_xp(suitcase_t *suit);
void init_hitboxes(suitcase_t *suit, sfImage* originalHitboxes);
