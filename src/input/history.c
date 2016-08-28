/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 17:57:43 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 19:44:06 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_list			*g_history_lst = NULL;
t_list			*g_current_node = NULL;

void	save_line(void)
{
	if ((g_line->state & LINE_SAVED) == 0)
	{
		if (g_line->chars != NULL)
		{
			g_line->state = g_line->state | LINE_SAVED;
			ft_lstadd(&g_history_lst, ft_lstnew(&g_line, sizeof(t_line)));
		}
		else
		{
			free(g_line);
			g_line = NULL;
		}
	}
}

int		ft_compare_line(void *d1, void *d2)
{
	t_line	**l1;
	t_line	**l2;
	char	*s1;
	char	*s2;
	int		r;

	l1 = (t_line**)d1;
	l2 = (t_line**)d2;
	s1 = ft_chars_to_str((*l1)->chars, ft_chars_len((*l1)->chars));
	s2 = ft_chars_to_str((*l2)->chars, ft_chars_len((*l2)->chars));
	r = ft_strncmp(s1, s2, ft_strlen(s2));
	free(s1);
	free(s2);
	return (r);
}
