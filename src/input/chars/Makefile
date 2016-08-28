# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 14:24:15 by rpereira          #+#    #+#              #
#    Updated: 2015/04/01 18:10:03 by rpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftc.a

SRCS =	ft_char_add.c \
		ft_char_push.c \
		ft_char_new.c \
		ft_char_add_index.c \
		ft_chars_len.c \
		ft_char_free.c \
		ft_chars_write.c \
		ft_chars_to_str.c \
		ft_char_remove.c \
		ft_char_remove_index.c \
		ft_chars_chars.c \
		ft_chars_cmp.c \
		ft_chars_ncmp.c \
		ft_char_at.c \
		ft_char_builder.c \
		ft_char_index_of.c

OBJ		= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra -Ofast -I ../../../libft

CC		= gcc $(FLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
