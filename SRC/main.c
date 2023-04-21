/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my_rpg.h"

int main(int ac, char **av)
{
    int fd;
    suitcase_t *suit = malloc(sizeof(suitcase_t));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        helper();
        return (0);
    } else
    if ((fd = open("script/coffre.txt", O_RDONLY)) == -1) {
        return (84);
    }
    init(suit);
    suit->var->size = read_map(suit, fd, "script/coffre.txt");
    suit->var->map = my_str_to_word_array(suit->var->size, '\n');
    char *temp = read_map(suit, fd, "script/mob.txt");
    suit->info_mobs = my_str_to_word_array(temp, '\n');
    open_window(suit);
    return 0;
}

void init_hitboxes(suitcase_t *suit, sfImage* originalHitboxes)
{
    unsigned int originalWidth = sfImage_getSize(originalHitboxes).x;
    unsigned int originalHeight = sfImage_getSize(originalHitboxes).y;
    unsigned int newWidth = (unsigned int)(originalWidth);
    unsigned int newHeight = (unsigned int)(originalHeight);
    suit->scaledHitboxes = sfImage_create(newWidth, newHeight);
    sfVector2u pixel;
    for (pixel.x = 0; pixel.x < newWidth; pixel.x++) {
        for (pixel.y = 0; pixel.y < newHeight; pixel.y++) {
            sfVector2f originalPixel = {(float)pixel.x / (float)newWidth * originalWidth, (float)pixel.y / (float)newHeight * originalHeight};
            sfColor color = sfImage_getPixel(originalHitboxes, (unsigned int)originalPixel.x, (unsigned int)originalPixel.y);
            sfImage_setPixel(suit->scaledHitboxes, pixel.x, pixel.y, color);
        }
    }
    suit->view->hitboxes = suit->scaledHitboxes;
}

void init_view(suitcase_t *suit)
{
    suit->booleen = 0;
    suit->fight->norm = sfView_create();
    sfView_setCenter(suit->fight->norm, (sfVector2f){960, 540});
    sfView_setSize(suit->fight->norm, (sfVector2f){1920, 1080});
    suit->view->inv = sfView_create();
    sfView_setSize(suit->view->inv, (sfVector2f){1920, 1080});
    sfView_setCenter(suit->view->inv, (sfVector2f){960, 540});
    suit->view->view = sfView_create();
    sfView_setSize(suit->view->view, (sfVector2f){480.0f, 270.0f});
    sfView_setCenter(suit->view->view, suit->view->position);
    sfVector2f zero = {0.0f, 0.0f};
    sfVector2f un = {1, 1};
    suit->image->tuto = create_sprite("assets/map/foret.png", zero, un, 0);
    suit->view->map = create_sprite("assets/map/map.png", zero, un, 0);
    suit->tuto = sfImage_createFromFile("assets/map/hitboxes_tuto.png");
    suit->originalHitboxes = sfImage_createFromFile("assets/map/hitboxes.png");
    suit->view->position = (sfVector2f){285.0f, 370.0f};
    init_hitboxes(suit, suit->tuto);
}

void init(suitcase_t *suit)
{
    init_malloc(suit);
    sfVideoMode video_mode = {1920, 1080, 30};
    suit->sett->mode.bitsPerPixel = 30;
    suit->sett->window = sfRenderWindow_create(video_mode, "RPG", sfResize | sfClose, NULL);
    suit->sett->width = sfRenderWindow_getSize(suit->sett->window).x;
    suit->sett->height = sfRenderWindow_getSize(suit->sett->window).y;
    suit->mouse->etat = 0;
    suit->var->sw = 0;
    init_var(suit);
    init_view(suit);
    insert_back_functions(suit);
    inite_sprites_menu(suit);
    create_use_fight(suit);
}

void insert_back(suitcase_t *suit, sfVector2f size,
void (*func_ptr)(suitcase_t *), void (*func_ptr_scene)(suitcase_t *))
{
    button_prop_t *new_node = malloc(sizeof(button_prop_t));
    button_prop_t *last = suit->button;

    new_node = button_create(suit->position, size, func_ptr, func_ptr_scene);
    new_node->next = NULL;
    if (suit->button == NULL) {
        suit->button = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void helper(void)
{
    return;
}
