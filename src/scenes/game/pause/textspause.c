/*
** EPITECH PROJECT, 2021
** textspause
** File description:
** textspause
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void init_pause_texts2(game_t *game, text_t **pause_texts)
{
    pause_texts[7] = init_text(my_itoa(game->player->stats.defense),
    "res/font/abang.otf", 40, (sfVector2f) {750, 230});
    pause_texts[8] = init_text(my_itoa(game->player->stats.damage),
    "res/font/abang.otf", 40, (sfVector2f) {750, 330});
    pause_texts[9] = init_text(my_itoa(game->player->stats.speed),
    "res/font/abang.otf", 40, (sfVector2f) {750, 430});
    pause_texts[10] = init_text(my_itoa(game->player->stats.atkspeed),
    "res/font/abang.otf", 40, (sfVector2f) {750, 530});
    pause_texts[11] = init_text(my_itoa(game->player->stats.range),
    "res/font/abang.otf", 40, (sfVector2f) {750, 630});
}

text_t **init_pause_texts(game_t *game)
{
    text_t **pause_texts = malloc(sizeof(text_t) * (NB_TEXTS_PA + 1));

    (pause_texts == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    pause_texts[NB_TEXTS_PA] = NULL;
    pause_texts[0] = init_text("Life", "res/font/abang.otf",
    50, (sfVector2f) {700, 75});
    pause_texts[1] = init_text("Defense", "res/font/abang.otf",
    50, (sfVector2f) {700, 175});
    pause_texts[2] = init_text("Damage", "res/font/abang.otf",
    50, (sfVector2f) {700, 275});
    pause_texts[3] = init_text("Speed", "res/font/abang.otf",
    50, (sfVector2f) {700, 375});
    pause_texts[4] = init_text("AtkSpeed", "res/font/abang.otf",
    50, (sfVector2f) {700, 475});
    pause_texts[5] = init_text("Range", "res/font/abang.otf",
    50, (sfVector2f) {700, 575});
    pause_texts[6] = init_text(my_itoa(game->player->stats.life),
    "res/font/abang.otf", 40, (sfVector2f) {750, 130});
    init_pause_texts2(game, pause_texts);
    return (pause_texts);
}