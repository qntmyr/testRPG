/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#pragma once

#include "my_rpg.h"
#include "stdbool.h"

enum repository_e { MENU_SCENE, GAME_SCENE, FIGHT_SCENE };

enum ButtonState{
    None,
    Hover,
    Pressed
};

enum Deplacement{
    Normal,
    Haut,
    Gauche,
    Droite,
    Bas,
};

typedef struct ref_s ref_t;

typedef struct button_prop_s button_prop_t;

typedef struct mouse_s{
    sfBool mouse_pressed;
    sfCursor *cursor_cross;
    sfCursor *cursor_hand;
    sfVector2f mouse_pos;
    int etat;
}mouse_t;

typedef struct sprite_s{
    char *path;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos_sprite;
    sfVector2f scale;
}sprite_t;

typedef struct param_s{
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    sfView* zoomedView;
    sfView* defaultView;
    unsigned int width;
    unsigned int height;
    sfClock* clock1;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock_pnj;
}param_t;

typedef struct images_s{
    sprite_t *main_character;
    sprite_t *main_character_red;
    sprite_t *botte;
    sprite_t *secret_1;
    sprite_t *secret_2;
    sprite_t *secret_3;
    sprite_t *secret_4;
    sprite_t *secret_5;
    sprite_t *secret_6;
    sprite_t *lampe;
    sprite_t *lampe_2;
    sprite_t *inventory;
    sprite_t *stats;
    sprite_t *coffre;
    sprite_t *coffre2;
    sprite_t *coffre3;
    sprite_t *black;
    sprite_t *tuto;
    sprite_t *pnj;
    sprite_t *point;
}images_t;

typedef struct rectangle_s{
    sfRectangleShape *inventary;
    sfRectangleShape *box1;
    sfRectangleShape *box2;
    sfRectangleShape *box3;
    sfRectangleShape *box4;
    sfRectangleShape *box5;
    sfRectangleShape *box6;
}rectangle_t;

typedef struct floatrect_s {
    sfFloatRect bounds_botte;
    sfFloatRect bounds_lampe;
    sfFloatRect bounds_main_character;
} floatrect_t;

typedef struct var_s {
    float vitesse_max;
    int speed_int;
    int vita_int;
    int force_int;
    sfVector2f coffre_pos;
    sfVector2f coffre_text;
    sfVector2f coffre_stats;
    float in_pos;
    float time; float time2;
    float delta; float delta2;
    int check;
    int change; float change_light;
    sfIntRect rect; int change_scene;
    sfCircleShape *circle; sfCircleShape *cir;
    int i; int j;
    char *size;
    char **map; int q;
    int h; int k;
    char *tableau; int *tab;
    int sw; int boo; int boo1;
    float change_xp; int lvl_up;
}var_t;

typedef struct info_to_view_s {
    sfView *view;
    sfView *inv;
    sfVector2f position;
    sprite_t *map;
    sprite_t *nouar;
    sfVector2f luminosite;
    sfColor pix;
    sfColor pix1;
    sfImage *test;
    sfTexture *hitboxes_texture;
    sfImage *hitboxes;
    sfCircleShape *blend_test;
} view_t;

typedef struct list_mob_s {
    sprite_t *mob;
    sfVector2f depart;
    sfVector2f arrive;
    int vitesse;
    sfColor color;
    int sens;
    int direction;
    sfVector2f stock;
    struct list_mob_s *next;
} mob_t;

typedef struct fight_scene_s {
    sprite_t *scene;
    sprite_t *jauge;
    sfView *norm;
} fight_t;

typedef struct suitcase_s{
    param_t *sett;
    int unused;
    enum repository_e repo;
    rectangle_t *rect;
    floatrect_t *floatrect;
    images_t *image;
    var_t *var;
    mouse_t *mouse;
    sfFont *font_arial;
    sfText* text;
    button_prop_t *button;
    sfVector2f position;
    view_t *view;
    mob_t *mob;
    fight_t *fight;
    char **info_mobs;
    sfRectangleShape *xp;
    sfRectangleShape *xp2;
    sfImage *tuto;
    sfImage* scaledHitboxes;
    sfImage *originalHitboxes;
    int booleen;
}suitcase_t;


struct button_prop_s{
    struct button_prop_s *next;
    sfVector2f pos_sprite;
    sfVector2f position;
    sfVector2f size;
    enum ButtonState state;
    sfRectangleShape* shape;
    void (*func_ptr)(suitcase_t *);
    void (*func_ptr_scene)(suitcase_t *);
    int boole;
};

struct ref_s{
    int nbr;
    void (*scene) (suitcase_t *);
    void (*eve) (suitcase_t *);
    void (*time) (suitcase_t *);
};

extern const ref_t ref[];
