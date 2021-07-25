/*
** EPITECH PROJECT, 2021
** map_s
** File description:
** map_s
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_map_s(game_t *game, object_t **map_s,
button_t **map_s_btn, text_t **map_s_text)
{
    map_s_text[0]->string = my_itoa(game->seed);
    sfText_setString(map_s_text[0]->text, map_s_text[0]->string);
    for (int i = 0; i != NB_PARALLAXS_MM; i++)
        sfRenderWindow_drawSprite(game->window,
        game->main_menu->mm_parallax[i]->parallax->object, NULL);
    for (int i = 0; i != NB_OBJECTS_MS; i++)
        sfRenderWindow_drawSprite(game->window, map_s[i]->object, NULL);
    for (int i = 0; i != 2; i++)
        sfRenderWindow_drawSprite(game->window, map_s_btn[i]->object->object,
        NULL);
    for (int i = 0; i != NB_TEXTS_MS; i++)
        sfRenderWindow_drawText(game->window, map_s_text[i]->text, NULL);
}

static text_t **init_map_s_text(game_t *game)
{
    text_t **map_s_text = malloc(sizeof(object_t) * (NB_TEXTS_MS + 1));

    (map_s_text == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    map_s_text[NB_TEXTS_MS] = NULL;
    map_s_text[0] = init_text(my_itoa(game->seed),
    "res/font/abang.otf", SEED_SELEC_SIZE, (sfVector2f) {792, 348});
    sfText_setLetterSpacing(map_s_text[0]->text, 5.01);
    return (map_s_text);
}

static object_t **init_map_s(game_t *game)
{
    object_t **map_s = malloc(sizeof(object_t) * (NB_OBJECTS_MS + 1));

    (map_s == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    map_s[NB_OBJECTS_MS] = NULL;
    map_s[0] = init_object("res/Scenes/MainMenu/seed.png",
    (sfVector2f) {761, 219}, (sfIntRect) {0, 0, 450, 200});
    map_s[1] = init_object("res/Scenes/MainMenu/seed_input.png",
    (sfVector2f) {771, 339}, (sfIntRect) {0, 0, 430, 70});
    return (map_s);
}

static button_t **init_map_s_button(game_t *game)
{
    button_t **map_s_btn = malloc(sizeof(button_t) * (NB_BUTTONS_MS + 1));

    (map_s_btn == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    map_s_btn[NB_BUTTONS_MS] = NULL;
    map_s_btn[0] = init_button("res/common/btn/bb.png",
    (sfVector2f) {0, 655}, (sfIntRect) {0, 0, 350, 40});
    map_s_btn[1] = init_button("res/Scenes/MainMenu/ppb.png",
    (sfVector2f) {882, 469}, (sfIntRect) {0, 0, 209, 40});
    return (map_s_btn);
}

void map_s(game_t *game, scenes_t **scenes)
{
    object_t **map_s = init_map_s(game);
    button_t **map_s_btn = init_map_s_button(game);
    text_t **map_s_text = init_map_s_text(game);

    srand(sfTime_asMicroseconds(sfClock_getElapsedTime(game->clock)));
    game->seed = rand() % (999999999 + 1);
    game->main_menu->other_menu = true;
    game->errorh->is_error ? scenes[game->current_scene]->quit_scene = true,
    game->main_menu->other_menu = false : 0;
    while (game->main_menu->other_menu) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            map_s_evt(game, scenes, map_s_btn);
        render_map_s(game, map_s, map_s_btn, map_s_text);
        parallax_menu(game->main_menu->mm_parallax);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_text_array(map_s_text, NB_TEXTS_MS);
    destroy_project_scene(map_s, NB_OBJECTS_MS, map_s_btn, NB_BUTTONS_MS);
}