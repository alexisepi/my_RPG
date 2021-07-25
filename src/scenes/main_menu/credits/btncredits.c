/*
** EPITECH PROJECT, 2021
** btncredits
** File description:
** btncredits
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void credits_bhh(button_t **credits_button, game_t *game)
{
    for (int i = 0; i != 1; i++) {
        if (button_is_hover(credits_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSprite_setTextureRect(credits_button[i]->object->object,
            (sfIntRect){0, 0, 425, 40});
        }
        else
            sfSprite_setTextureRect(credits_button[i]->object->object,
            credits_button[i]->object->rect);
    }
}

void credits_bhc(button_t **credits_button, game_t *game)
{
    for (int i = 0; i != 1; i++) {
        if (button_is_hover(credits_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(credits_button[i]->object->object,
            (sfVector2f) {credits_button[i]->object->pos.x,
            (credits_button[i]->object->pos.y + 10)});
            switch (i)  {
                case 0: game->main_menu->other_menu = false;
                    break;
            }
        }
    }
}