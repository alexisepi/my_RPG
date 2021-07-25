/*
** EPITECH PROJECT, 2021
** pause_gamemenu
** File description:
** pause_gamemenu
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static void render_pause(game_t *game, object_t **pause_obj,
button_t **pause_btn, text_t **pause_text)
{
    if (!game->main_game->is_faded)
        sfRenderWindow_drawRectangleShape(game->window,
        game->main_game->fade, NULL);
    for (int i = 0; i != NB_OBJECTS_PA; i++)
        sfRenderWindow_drawSprite(game->window, pause_obj[i]->object, NULL);
    for (int i = 0; i != NB_BUTTONS_PA; i++)
        sfRenderWindow_drawSprite(game->window,
        pause_btn[i]->object->object, NULL);
    for (int i = 0; i != NB_TEXTS_PA; i++)
        sfRenderWindow_drawText(game->window, pause_text[i]->text, NULL);
}

static object_t **init_pause(game_t *game)
{
    object_t **pause_obj = malloc(sizeof(object_t) * (NB_OBJECTS_PA + 1));

    (pause_obj == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    pause_obj[NB_OBJECTS_PA] = NULL;
    pause_obj[0] = init_object("res/Scenes/Game/title_bl.png",
    (sfVector2f) {38, 38}, (sfIntRect) {0, 0, 490, 110});
    return (pause_obj);
}

static button_t **init_pause_btn(game_t *game)
{
    button_t **pause_btn = malloc(sizeof(button_t) * (NB_BUTTONS_PA + 1));

    (pause_btn == NULL) ? set_error(game, MALLOC_ERROR) : 0;
    pause_btn[NB_BUTTONS_PA] = NULL;
    pause_btn[0] = init_button("res/Scenes/Game/rb.png",
    (sfVector2f) {0, 275}, (sfIntRect) {0, 0, 350, 40});
    pause_btn[1] = init_button("res/Scenes/Game/mmb.png",
    (sfVector2f) {0, 355}, (sfIntRect) {0, 0, 350, 40});
    pause_btn[2] = init_button("res/common/btn/ob.png",
    (sfVector2f) {0, 435}, (sfIntRect) {0, 0, 350, 40});
    pause_btn[3] = init_button("res/common/btn/eb.png",
    (sfVector2f) {0, 515}, (sfIntRect) {0, 0, 350, 40});
    return (pause_btn);
}

void pause_game(game_t *game, scenes_t **scenes)
{
    object_t **pause_obj = init_pause(game);
    button_t **pause_btn = init_pause_btn(game);
    text_t **pause_text = init_pause_texts(game);

    game->main_game->game_paused = true;
    while (game->main_game->game_paused) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            pause_game_evt(game, scenes, pause_btn);
        render_pause(game, pause_obj, pause_btn, pause_text);
        game->main_game->is_faded = true;
        sfRenderWindow_display(game->window);
    }
    game->main_game->is_faded = false;
    sfRenderWindow_clear(game->window, sfBlack);
    destroy_project_scene(pause_obj, NB_OBJECTS_PA, pause_btn, NB_BUTTONS_PA);
}