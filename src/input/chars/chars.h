/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 08:53:38 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:11:40 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARS_H
# define CHARS_H

# include "libft.h"
# include <stdint.h>

typedef struct	s_char
{
	int				state;
	char			c;
	struct s_char	*next;
}				t_char;

enum			e_char_state
{
	CHAR_SELECTED = 1
};

t_char			*ft_char_new(char c);
t_char			*ft_char_build_from_str(char *str);
void			ft_char_add(t_char **lst, t_char *c);
void			ft_char_push(t_char **lst, t_char *ch);
void			ft_char_add_index(t_char **lst, t_char *c, int index);
char			*ft_chars_to_str(t_char *lst, int len);

int				ft_chars_last_index_of(t_char *chars, char c);
int				ft_chars_index_of(t_char *chars, char c);
int				ft_chars_index_of_from(t_char *chars, char c, int from);
int				ft_chars_last_index_of_from(t_char *chars, char c, int from);

void			ft_chars_write_from_index(t_char *lc, int l, int ind);
void			ft_chars_write_to_index(t_char *lst, int l, int ind);
void			ft_chars_write(t_char *lst, int len);
int				ft_chars_len(t_char *lst);
void			ft_chars_free(t_char **lst);
void			ft_char_remove_first(t_char **lst);
void			ft_char_remove_last(t_char **lst);
void			ft_char_remove_index(t_char **lst, int index);
int				ft_chars_cmp(t_char *c1, t_char *c2);
int				ft_chars_ncmp(t_char *c1, t_char *c2, int n);
int				ft_chars_chars(t_char *c1, t_char *c2);

char			ft_char_at(t_char *c, int len, int index);
int				ft_chars_index_of(t_char *chars, char c);
int				ft_chars_last_index_of(t_char *chars, char c);

#endif
