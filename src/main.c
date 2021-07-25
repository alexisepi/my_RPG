/*
** EPITECH PROJECT, 2021
** main
** File description:
** Main File
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

int main(void)
{
    game_t *game = init_game();
    scenes_t **scenes = init_scenes_array(game);

    if (!sfRenderWindow_isOpen(game->window))
        return (destroy_error(game, scenes, WINDOW_CREATE_ERROR));
    if (game->errorh->is_error)
            return (destroy_error(game, scenes, game->errorh->error_id));
    sfMusic_play(game->audio->bg_music->music);
    sfMusic_setLoop(game->audio->bg_music->music, sfTrue);
    while (game->current_scene != SCENE_EXIT) {
        scenes[game->current_scene]->function(game, scenes);
        scenes[game->current_scene]->quit_scene = false;
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->errorh->is_error)
            return (destroy_error(game, scenes, game->errorh->error_id));
    }
    return (destroy_error(game, scenes, NORMAL));
}