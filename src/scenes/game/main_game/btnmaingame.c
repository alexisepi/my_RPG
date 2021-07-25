/*
** EPITECH PROJECT, 2021
** btnmainmenu
** File description:
** btnmainmenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void main_game_bhh(button_t **game_btn, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_MG; i++) {
        if (button_is_hover(game_btn[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSprite_setTextureRect(game_btn[i]->object->object,
            (sfIntRect){0, 0, 425, 40});
        }
        else
            sfSprite_setTextureRect(game_btn[i]->object->object,
            game_btn[i]->object->rect);
    }
}

void main_game_bhc(button_t **game_btn, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_MG; i++) {
        if (button_is_hover(game_btn[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(game_btn[i]->object->object, (sfVector2f)
            {game_btn[i]->object->pos.x, (game_btn[i]->object->pos.y += 10)});
            switch (i) {
                default:
                    break;
            }
        }
    }
}