/*
** EPITECH PROJECT, 2021
** errorhandler
** File description:
** An file containing error handler functions
*/

#include "my.h"
#include "exielcl.h"
#include "exielcsfml.h"

int error_handler(int error_id)
{
    switch (error_id) {
        case 0:
            return (NORMAL);
            break;
        case WINDOW_CREATE_ERROR:
            my_printf("%w", "ERROR: Cannot Create the Window.\n");
            return (ERROR);
            break;
        case MALLOC_ERROR:
            my_printf("%w", "ERROR: Cannot Allocate Memory.\n");
            return (ERROR);
            break;
        default: my_printf("%w", "ERROR: Unknown Error.\n");
            return (ERROR);
            break;
    }
}