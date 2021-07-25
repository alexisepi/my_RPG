/*
** EPITECH PROJECT, 2021
** B-MUL-200-REN-2-1-myrpg-nathan.duchesne
** File description:
** render_map
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

static object_t *render_map3(int nb, int pos_x, int pos_y)
{
    switch (nb) {
        case MAP_GRAVEL1: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){0, 130, 64, 64}));
            break;
        case MAP_GRAVEL2: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){65, 130, 64, 64}));
            break;
        case MAP_GRAVEL3: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){130, 130, 64, 64}));
            break;
        case MAP_GRAVEL4: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){195, 0, 64, 64}));
            break;
        default: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){0, 65, 64, 64}));
            break;
    }
}

static object_t *render_map2(int nb, int pos_x, int pos_y)
{
    switch (nb) {
        case MAP_ENV_1: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){195, 130, 64, 64}));
            break;
        case MAP_ENV_2: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){260, 130, 64, 64}));
            break;
        default: return (render_map3(nb, pos_x, pos_y));
            break;
    }
}

object_t *render_map(game_t *game, int height, int width)
{
    int pos_x = (64 * width), pos_y = (64 * height);

    switch (game->generator->actual->sprite[height][width]) {
        case MAP_GROUND: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){195, 65, 64, 64}));
            break;
        case MAP_VOID: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){0, 65, 64, 64}));
            break;
        case MAP_WALL: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){0, 0, 64, 64}));
            break;
        case MAP_DOOR_1: return (init_object("res/Scenes/Game/map_tiles.png",
        (sfVector2f){pos_x, pos_y}, (sfIntRect){325, 65, 64, 64}));
            break;
        default:
            return (render_map2(game->generator->actual->sprite[height][width],
            pos_x, pos_y));
            break;
    }
}