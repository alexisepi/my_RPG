/*
** EPITECH PROJECT, 2021
** init_struct2
** File description:
** init_struct2
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

spinbox_t *init_option_spinbox(float volume)
{
    sfVector2f spinbox_pos = {150, 160};

    text_t *spinbox_text = init_text(my_itoa(volume), "res/font/abang.otf",
    AUDIO_TEXT_SIZE, (sfVector2f) {(spinbox_pos.x + 5), spinbox_pos.y});
    spinbox_t *spinbox = init_spinbox(MAX_VOLUME, MIN_VOLUME,
    spinbox_pos, spinbox_text);
    return (spinbox);
}

main_game_t *init_main_game(void)
{
    main_game_t *main_game = malloc(sizeof(main_game_t));
    sfRectangleShape *rect;

    rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, (sfColor){11, 19, 30, 200});
    sfRectangleShape_setOrigin(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1280, 720});
    main_game->fade = rect;
    main_game->is_faded = false;
    main_game->game_paused = false;
    main_game->game_paused_paused = false;
    return (main_game);
}

option_t *init_game_option(void)
{
    option_t *option = malloc(sizeof(option_t));
    char **keys = malloc(sizeof(char *) * 101);

    for (int i = 0; i != 101; i++) {
        keys[i] = malloc(sizeof(char) * 14);
        for (int j = 0; j != 14; j++)
            keys[i][j] = '\0';
    }
    option->key_pause = DEF_KEY_PAUSE;
    option->key_up = DEF_KEY_UP;
    option->key_down = DEF_KEY_DOWN;
    option->key_right = DEF_KEY_RIGHT;
    option->key_left = DEF_KEY_LEFT;
    option->key_attack = DEF_KEY_ATTACK;
    option->keys = keys;
    option->upd_key = false;
    option->key_to_upd = 0;
    init_option_key(keys);
    return (option);
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->player = init_object("res/Scenes/Game/player.png",
    (sfVector2f) {PPOS_X, PPOS_Y}, (sfIntRect) {0, 203, 49, 49});
    sfSprite_setScale(player->player->object, (sfVector2f) {2, 2});
    player->dir = 0;
    player->mov_cnt = 0;
    player->attack = false;
    player->attack_cnt = 0;
    player->stats = (stats_t) {100, 50, 45, 30, 20, 20};
    return (player);
}

scenes_t **init_scenes_array(game_t *game)
{
    scenes_t **scenes = malloc(sizeof(scenes_t) * (SCENE_COUNT + 1));

    (scenes == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    scenes[SCENE_COUNT] = NULL;
    scenes[SCENE_EXIT] = init_scene(SCENE_EXIT, &mainmenu);
    scenes[SCENE_MAINMENU] = init_scene(SCENE_MAINMENU, &mainmenu);
    scenes[SCENE_MAP] = init_scene(SCENE_MAP, &mainmenu);
    scenes[SCENE_GAME] = init_scene(SCENE_GAME, &maingame);
    return (scenes);
}