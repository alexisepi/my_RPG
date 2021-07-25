##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Exiel CSFML Lib Makefile
##

SRC	= 	my_utils/my_timer.c				\
		my_utils/move_rect.c			\
		my_utils/check_parallax.c		\
		my_utils/spinbox_hover.c		\
		my_utils/object_hover.c			\
\
		buttonhandler/button_hover.c	\
\
		init_struct/init_button.c		\
		init_struct/init_circle.c		\
		init_struct/init_music.c		\
		init_struct/init_object.c		\
		init_struct/init_rectangle.c	\
		init_struct/init_scene.c		\
		init_struct/init_sound.c		\
		init_struct/init_text.c			\
		init_struct/init_parallax.c		\
		init_struct/init_spinbox.c

BUILD_DIR = build
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
CFLAGS = -I includes/

NAME = libecsfml.a

#Mandatory rules

all: head h_normal $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp includes/exielcsfml.h ../../includes/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		rm -f ../../includes/exielcsfml.h

re:	fclean all

#Additional rules

$(BUILD_DIR)/%.o: %.c
					@mkdir -p $(@D)
					@echo "  CC       $<"
					@$(CC) $(CFLAGS) -c $< -o $@

head:
			@echo "╔═══════════════════════════════╗"
			@echo "║  _____          _          _  ║"
			@echo "║ |  ___|        (_)        | | ║"
			@echo "║ | |__   __  __  _    ___  | | ║"
			@echo "║ |  __|  \ \/ / | |  / _ \ | | ║"
			@echo "║ | |___   >  <  | | |  __/ | | ║"
			@echo "║ \____/  /_/\_\ |_|  \___| |_| ║"
			@echo "║                               ║"

h_normal:
			@echo "║    Compiling a "perfect" lib.   ║"
			@echo "║           EXIELCSFML          ║"
			@echo "╚═══════════════════════════════╝"
			@echo

.PHONY: clean fclean