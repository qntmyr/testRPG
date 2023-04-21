/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my_rpg.h"
#include "stdbool.h"

const ref_t ref[] = {
    {MENU_SCENE, &scene_menu, &event_menu, &time_menu} ,
    {GAME_SCENE, &scene_game, &event_game, &time_game} ,
    {FIGHT_SCENE, &scene_fight, &event_fight, &time_fight} ,
    {'\0'} ,
};

int open_window(suitcase_t *suit)
{
    define_mob(suit);
    suit->repo = MENU_SCENE;
    while (sfRenderWindow_isOpen(suit->sett->window)) {
        while (sfRenderWindow_pollEvent(suit->sett->window, &(suit->sett->event))) {
            event(suit);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEnter))
            suit->repo = FIGHT_SCENE;
        scene(suit);
    }
    return 0;
}

void event(suitcase_t *suit)
{
    if (suit->sett->event.type == sfEvtClosed ||sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(suit->sett->window);
    if (suit->sett->event.type == sfEvtResized) {
        sfFloatRect visibleArea = (sfFloatRect){0.f, 0.f,
        (float)suit->sett->event.size.width, (float)suit->sett->
        event.size.height};
        // sfView_setViewport(suit->view->view, visibleArea);
        sfRenderWindow_setView(suit->sett->window,
        sfView_createFromRect(visibleArea));
    }
    ref[suit->repo].eve(suit);
    suit->mouse->mouse_pos = sfRenderWindow_mapPixelToCoords(suit->sett->window
    , sfMouse_getPositionRenderWindow(suit->sett->window), NULL);
}

void scene(suitcase_t *suit)
{
    sfRenderWindow_clear(suit->sett->window, sfColor_fromRGB(0, 0 ,0));
    ref[suit->repo].time(suit);
    ref[suit->repo].scene(suit);
    sfRenderWindow_display(suit->sett->window);
    return;
}
