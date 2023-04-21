/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../../include/my_rpg.h"

void button_set_color(button_prop_t *button, sfColor color)
{
    sfRectangleShape_setFillColor(button->shape, color);
}

int button_update(button_prop_t *button, suitcase_t *suit)
{
    if (button->state == Pressed) {
        button->func_ptr(suit);
        return 0;
    }
    sfFloatRect buttonBounds = sfRectangleShape_getGlobalBounds(button->shape);
    if (sfFloatRect_contains(&buttonBounds, suit->mouse->mouse_pos.x,
    suit->mouse->mouse_pos.y) && suit->sett->event.type != sfEvtResized) {
        if (button_style(suit, button) == 3)
            return 3;
    } else {
        button->state = None;
        button_set_color(button, sfTransparent);
        sfRectangleShape_setOutlineThickness(button->shape, 0.0f);
        return 1;
    }
    return 0;
}

int button_update_scene(button_prop_t *button, suitcase_t *suit)
{
    if (button->state == Pressed) {
        button->func_ptr_scene(suit);
        return 3;
    }
    return 0;
}

button_prop_t *button_create(sfVector2f position, sfVector2f size,
void (*func_ptr)(suitcase_t *), void (*func_ptr_scene)(suitcase_t *))
{
    button_prop_t *button = malloc(sizeof(button_prop_t));
    button->position = position;
    button->size = size;
    button->func_ptr = func_ptr;
    button->func_ptr_scene = func_ptr_scene;
    button->state = None;
    button->shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->shape, position);
    sfRectangleShape_setSize(button->shape, size);
    button_set_color(button, sfBlack);
    return button;
}

void button_destroy(button_prop_t *button)
{
    sfRectangleShape_destroy(button->shape);
    free(button);
}
