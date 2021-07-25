/*
** EPITECH PROJECT, 2021
** btnhtp
** File description:
** btnhtp
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void htp_bhh(button_t **htp_button, game_t *game)
{
    for (int i = 0; i != 1; i++) {
        if (button_is_hover(htp_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSprite_setTextureRect(htp_button[i]->object->object,
            (sfIntRect){0, 0, 425, 40});
        }
        else
            sfSprite_setTextureRect(htp_button[i]->object->object,
            htp_button[i]->object->rect);
    }
}

void htp_bhc(button_t **htp_button, game_t *game)
{
    for (int i = 0; i != 1; i++) {
        if (button_is_hover(htp_button[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(htp_button[i]->object->object, (sfVector2f)
            {htp_button[i]->object->pos.x,
            (htp_button[i]->object->pos.y + 10)});
            switch (i)  {
                case 0: game->main_menu->other_menu = false;
                    break;
            }
        }
    }
}