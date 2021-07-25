/*
** EPITECH PROJECT, 2021
** init_spinbox
** File description:
** init_spinbox
*/

#include "exielcsfml.h"
#include <stdlib.h>

char *my_itoa(int nb);

spinbox_t *init_spinbox(int max_value, int min_value, sfVector2f pos,
text_t *spinbox_text)
{
    spinbox_t *spinbox = malloc(sizeof(spinbox_t));

    spinbox->text_object = init_object("lib/exielcsfml/res/spinboxsheet.png",
    pos, (sfIntRect) {0, 0, 100, 50});
    spinbox->button_top = init_object("lib/exielcsfml/res/spinboxsheet.png",
    (sfVector2f) {pos.x + 100, pos.y}, (sfIntRect) {100, 0, 50, 25});
    spinbox->button_bottom = init_object("lib/exielcsfml/res/spinboxsheet.png",
    (sfVector2f) {pos.x + 100, pos.y + 25}, (sfIntRect) {100, 25, 50, 25});
    spinbox->current_value = max_value;
    spinbox->spinbox_text = spinbox_text;
    spinbox->max_value = max_value;
    spinbox->min_value = min_value;
    return (spinbox);
}

void destroy_spinbox(spinbox_t *spinbox)
{
    destroy_text(spinbox->spinbox_text);
    destroy_object(spinbox->button_top);
    destroy_object(spinbox->button_bottom);
    destroy_object(spinbox->text_object);
    free(spinbox);
}

void destroy_spinbox_array(spinbox_t **spinboxs, int nb_spinboxs)
{
    for (int i = 0; i != nb_spinboxs; i++)
        destroy_spinbox(spinboxs[i]);
    free(spinboxs);
}

void draw_spinbox(sfRenderWindow *window, spinbox_t *spinbox)
{
    sfRenderWindow_drawSprite(window, spinbox->text_object->object, NULL);
    sfRenderWindow_drawSprite(window, spinbox->button_top->object, NULL);
    sfRenderWindow_drawSprite(window, spinbox->button_bottom->object, NULL);
    sfRenderWindow_drawText(window, spinbox->spinbox_text->text, NULL);
}