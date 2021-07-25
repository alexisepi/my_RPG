/*
** EPITECH PROJECT, 2021
** spinbox_option
** File description:
** spinbox_option
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void set_spinbox(game_t *game, spinbox_t *spinbox, int flag)
{
    update_volume(game);
    if (flag == 0) {
        if ((spinbox->current_value - 1) >= spinbox->min_value) {
            spinbox->current_value -= 1;
            spinbox->spinbox_text->string = my_itoa(spinbox->current_value);
            sfText_setString(spinbox->spinbox_text->text,
            spinbox->spinbox_text->string);
        }
    } else {
        if ((spinbox->current_value + 1) <= spinbox->max_value) {
            spinbox->current_value += 1;
            spinbox->spinbox_text->string = my_itoa(spinbox->current_value);
            sfText_setString(spinbox->spinbox_text->text,
            spinbox->spinbox_text->string);
        }
    }
}

void option_sbh(spinbox_t *spinbox, game_t *game)
{
    if (spinbox_is_hover(spinbox,
    sfMouse_getPositionRenderWindow(game->window)) == 1) {
        sfSprite_setTextureRect(spinbox->button_top->object,
        (sfIntRect){150, 0, 50, 25});
        sfSprite_setTextureRect(spinbox->button_bottom->object,
        spinbox->button_bottom->rect);
    } else if (spinbox_is_hover(spinbox,
    sfMouse_getPositionRenderWindow(game->window)) == 2) {
        sfSprite_setTextureRect(spinbox->button_bottom->object,
        (sfIntRect){150, 25, 50, 25});
        sfSprite_setTextureRect(spinbox->button_top->object,
        spinbox->button_top->rect);
    }
    else {
        sfSprite_setTextureRect(spinbox->button_top->object,
        spinbox->button_top->rect);
        sfSprite_setTextureRect(spinbox->button_bottom->object,
        spinbox->button_bottom->rect);
    }
}

void option_sbhc(spinbox_t *spinbox, game_t *game)
{
    if (spinbox_is_hover(spinbox,
    sfMouse_getPositionRenderWindow(game->window)) == 1)
        set_spinbox(game, spinbox, 1);
    else if (spinbox_is_hover(spinbox,
    sfMouse_getPositionRenderWindow(game->window)) == 2)
        set_spinbox(game, spinbox, 0);
}