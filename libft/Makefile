# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 14:24:15 by rpereira          #+#    #+#              #
#    Updated: 2015/04/03 09:52:31 by rpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_strlen.c ft_atoi.c ft_memset.c \
		  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memalloc.c ft_strcat.c \
		  ft_memmove.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_toupper.c \
		  ft_tolower.c ft_isalnum.c ft_strcpy.c ft_strdup.c ft_strstr.c \
		  ft_strlcat.c ft_strcmp.c ft_strchr.c ft_strncmp.c ft_strncpy.c \
		  ft_memchr.c ft_memcmp.c ft_strncat.c ft_strnstr.c ft_strrchr.c \
		  ft_isalpha.c ft_strnew.c ft_strrev.c ft_memdel.c ft_striter.c \
		  ft_striteri.c ft_strmap.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_ccount.c \
		  ft_itoa.c ft_strdel.c ft_strclr.c ft_strmapi.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstsize.c ft_lstmap.c ft_lstsize.c ft_lstpush.c ft_nbrlen.c \
		  ft_swap.c btree_create_node.c btree_insert_data.c \
		  btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c \
		  btree_search_item.c btree_level_count.c \
		  get_next_line.c ft_strsplit_util.c ft_lstfree.c \
		  ft_htab.c ft_htab_util.c \
		  ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar.c ft_wchar.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		  ft_void_cmp.c ft_voidvoid.c ft_match.c ft_index_of.c

OBJ		= $(SRCS:.c=.o)

FLAGS	= -O2

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
