/*
** EPITECH PROJECT, 2021
** init_struct
** File description:
** init_struct
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static sound_t **init_sounds_array(game_t *game)
{
    sound_t **sounds = malloc(sizeof(sound_t) * SOUND_COUNT);

    (sounds == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    sounds[SOUND_BTN] = init_sound(false, 100, "res/audio/btn.ogg");
    return (sounds);
}

static errorh_t *init_errorh(void)
{
    errorh_t *errorh = malloc(sizeof(errorh_t));

    errorh->error_id = NORMAL;
    errorh->is_error = false;
    return (errorh);
}

audio_t *init_audio(game_t *game)
{
    audio_t *audio = malloc(sizeof(audio_t));

    audio->bg_music = init_music(sfTrue, 100, "res/audio/macedoine.ogg");
    audio->sounds = init_sounds_array(game);
    audio->bgm_spinbox = init_option_spinbox(audio->bg_music->volume);
    return (audio);
}

void init_game2(game_t *game)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));

    game->player = init_player();
    game->main_menu = main_menu;
    game->main_menu->other_menu = false;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, GAME_NAME, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, GAME_FRAMERATE);
    game->clock = sfClock_create();
    game->current_scene = SCENE_MAINMENU;
    game->audio = init_audio(game);
    game->main_game = init_main_game();
    game->option = init_game_option();
    game->mob = init_enemy("res/Scenes/Game/wizard.png",
    (sfVector2f) {MOBPOS_X, MOBPOS_Y}, (sfIntRect) {0, 300, 150, 150});
    sfSprite_setScale(game->mob->enemy->object, (sfVector2f) {1.5, 1.5});
    game->errorh = init_errorh();
    game->seed = 0;
    game->nb_input = 10;
    game->generator = init_generator();
    init_game2(game);
    return (game);
}