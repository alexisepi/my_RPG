/*
** EPITECH PROJECT, 2021
** init_main_game
** File description:
** init_main_game
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

object_t **init_game_map(game_t *game)
{
    object_t **game_map = malloc(sizeof(object_t) * (MAP_WIDTH * MAP_HEIGHT));
    int ptr = 0;

    (!game_map) ? set_error(game, MALLOC_ERROR) : 0;
    (gen_manage(game) == 84) ? set_error(game, WRONG_INIT_GEN) : 0;
    for (int leny = 0; leny != MAP_HEIGHT; leny++) {
        for (int lenx = 0; lenx != MAP_WIDTH; lenx++, ptr++) {
            game_map[ptr] = render_map(game, leny, lenx);
        }
    }
    return (game_map);
}