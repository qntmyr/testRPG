/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../../include/my_rpg.h"

int button_style(suitcase_t *suit, button_prop_t *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_button(suit);
        button->state = Pressed;
        button_set_color(button, (sfColor){200, 200, 200, 255});
        button->func_ptr(suit);
        return 3;
    } else {
        button->state = Hover;
        sfRectangleShape_setOutlineThickness(button->shape, 1.0f);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
        return 3;
    }
    return 0;
}
