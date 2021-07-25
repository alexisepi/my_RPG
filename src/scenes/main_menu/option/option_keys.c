/*
** EPITECH PROJECT, 2021
** option_keys
** File description:
** option_keys
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void option_set_text_color(text_t **option_texts)
{
    sfText_setColor(option_texts[0]->text, sfBlack);
    sfText_setColor(option_texts[1]->text, sfBlack);
    sfText_setColor(option_texts[2]->text, sfBlack);
    sfText_setColor(option_texts[3]->text, sfBlack);
    sfText_setColor(option_texts[4]->text, sfBlack);
    sfText_setColor(option_texts[5]->text, sfBlack);
    sfText_setColor(option_texts[11]->text, sfBlack);
}

static void init_option_keys_text(game_t *game, text_t **option_texts)
{
    option_texts[6] = init_text(game->option->keys[game->option->key_up],
    "res/font/asdonuts.otf", 40, (sfVector2f) {600, 150});
    option_texts[7] = init_text(game->option->keys[game->option->key_down],
    "res/font/asdonuts.otf", 40, (sfVector2f) {600, 250});
    option_texts[8] = init_text(game->option->keys[game->option->key_right],
    "res/font/asdonuts.otf", 40, (sfVector2f) {600, 350});
    option_texts[9] = init_text(game->option->keys[game->option->key_left],
    "res/font/asdonuts.otf", 40, (sfVector2f) {600, 450});
    option_texts[10] = init_text(game->option->keys[game->option->key_pause],
    "res/font/asdonuts.otf", 40, (sfVector2f) {600, 550});
    option_texts[11] = init_text("Attack", "res/font/abang.otf",
    50, (sfVector2f) {500, 600});
    option_texts[12] = init_text(game->option->keys[game->option->key_attack],
    "res/font/asdonuts.otf", 40, (sfVector2f) {600, 650});
}

text_t **init_option_text(game_t *game)
{
    text_t **option_texts = malloc(sizeof(text_t) * (NB_TEXTS_OP + 1));

    (option_texts == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    option_texts[NB_TEXTS_OP] = NULL;
    option_texts[0] = init_text("Volume", "res/font/abang.otf",
    50, (sfVector2f) {100, 100});
    option_texts[1] = init_text("Up", "res/font/abang.otf",
    50, (sfVector2f) {500, 100});
    option_texts[2] = init_text("Down", "res/font/abang.otf",
    50, (sfVector2f) {500, 200});
    option_texts[3] = init_text("Right", "res/font/abang.otf",
    50, (sfVector2f) {500, 300});
    option_texts[4] = init_text("Left", "res/font/abang.otf",
    50, (sfVector2f) {500, 400});
    option_texts[5] = init_text("Pause", "res/font/abang.otf",
    50, (sfVector2f) {500, 500});
    init_option_keys_text(game, option_texts);
    option_set_text_color(option_texts);
    return (option_texts);
}