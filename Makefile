# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 14:24:15 by rpereira          #+#    #+#              #
#    Updated: 2015/04/03 10:47:20 by rpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_minishell3

SRC_DIR = ./src/
SRC		= main/main.c main/env.c main/loop.c main/prompt.c \
		  main/sh3_error.c main/sh3_logger.c \
		  init/cmd_loader.c init/config.c init/term_init.c \
		  builtin/builtin.c builtin/builtin_cd.c builtin/builtin_env.c \
		  env/env.c env/env_builder.c \
		  exec/cmd_exec.c exec/cmd_utils.c exec/fildes_utils.c \
		  exec/pipeline_exec.c exec/pipeline.c exec/redirections.c \
		  parser/ft_strsplit_cmd.c \
		  parser/parser.c parser/parser_first.c \
		  input/cursor.c input/input.c input/termios_utils.c \
		  input/globals.c input/key_handler_arrow.c \
		  input/key_handler.c input/key_handler_tab.c \
		  input/key_handler_history.c \
		  input/key_handler_special.c input/key_handler_shift.c \
		  input/key_handler_backspace.c \
		  input/history.c input/parenthese.c input/parenthese_state.c \
		  input/key_handler_ctrl.c input/key_handler_copy.c \
		  input/key_handler_delete.c input/key_handler_enter.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ		= $(SRCS:.c=.o)
FLAGS	= -Wall -Werror -Wextra -Ofast
CC		= gcc $(FLAGS)
LIB		= ./src/input/chars/libftc.a ./libft/libft.a -lncurses
INC		= -I ./libft/ -I ./includes -I ./src/input/chars

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C ./src/input/chars/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

clean:
	make -C libft/ clean
	make -C ./src/input/chars/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	make -C ./src/input/chars/ fclean
	rm -rf $(NAME)

re: fclean all
