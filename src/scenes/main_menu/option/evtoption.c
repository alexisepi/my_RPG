/*
** EPITECH PROJECT, 2021
** evtoption
** File description:
** evtoption
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void upd_key2(game_t *game, text_t **option_text)
{
    switch (game->option->key_to_upd) {
        case 3: game->option->key_left = game->event.key.code;
            sfText_setString(option_text[9]->text,
            game->option->keys[game->option->key_left]);
            break;
        case 4: game->option->key_pause = game->event.key.code;
            sfText_setString(option_text[10]->text,
            game->option->keys[game->option->key_pause]);
            break;
        case 5: game->option->key_attack = game->event.key.code;
            sfText_setString(option_text[12]->text,
            game->option->keys[game->option->key_attack]);
            break;
    }
    game->option->upd_key = false;
}

static void upd_key(game_t *game, text_t **option_text)
{
    if (game->event.key.code < 0 || game->event.key.code > 100)
        return;
    switch (game->option->key_to_upd) {
        case 0: game->option->key_up = game->event.key.code;
            sfText_setString(option_text[6]->text,
            game->option->keys[game->option->key_up]);
            break;
        case 1: game->option->key_down = game->event.key.code;
            sfText_setString(option_text[7]->text,
            game->option->keys[game->option->key_down]);
            break;
        case 2: game->option->key_right = game->event.key.code;
            sfText_setString(option_text[8]->text,
            game->option->keys[game->option->key_right]);
            break;
        default: upd_key2(game, option_text);
            break;
    }
    game->option->upd_key = false;
}

void option_evt(game_t *game, scenes_t **scenes, button_t **option_btn,
text_t **option_texts)
{
    switch (game->event.type) {
        case sfEvtClosed: game->main_menu->other_menu = false;
            game->current_scene = SCENE_EXIT;
            scenes[game->current_scene]->quit_scene = true;
            break;
        case sfEvtMouseButtonPressed:
            option_sbhc(game->audio->bgm_spinbox, game);
            option_bhc(option_btn, game);
            break;
        case sfEvtMouseMoved:
            option_sbh(game->audio->bgm_spinbox, game);
            option_bhh(option_btn, game);
            break;
        case sfEvtKeyPressed: if (game->option->upd_key) {
            upd_key(game, option_texts);
            }
            break;
        default:
            break;
    }
}