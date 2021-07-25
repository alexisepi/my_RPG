/*
** EPITECH PROJECT, 2021
** btnpause_game
** File description:
** btnpause_game
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

void optpause_bhh(button_t **optpause_btn, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_OPP; i++) {
        if (button_is_hover(optpause_btn[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSprite_setTextureRect(optpause_btn[i]->object->object,
            (sfIntRect){0, 0, 425, 40});
        }
        else
            sfSprite_setTextureRect(optpause_btn[i]->object->object,
            optpause_btn[i]->object->rect);
    }
}

void optpause_bhc(button_t **optpause_btn, game_t *game)
{
    for (int i = 0; i != NB_BUTTONS_OPP; i++) {
        if (button_is_hover(optpause_btn[i],
        sfMouse_getPositionRenderWindow(game->window))) {
            sfSound_play(game->audio->sounds[SOUND_BTN]->sound);
            sfSprite_setPosition(optpause_btn[i]->object->object,
            (sfVector2f) {optpause_btn[i]->object->pos.x,
            (optpause_btn[i]->object->pos.y + 10)});
            switch (i)  {
                case 0: game->main_game->game_paused_paused = false;
                    break;
            }
        }
    }
}