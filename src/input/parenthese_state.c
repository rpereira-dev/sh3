/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 13:39:45 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 15:59:05 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		check_parentheses(void)
{
	int	i;

	i = 0;
	while (i < MAX_PARENTHESE)
	{
		if (g_parenthese[i].state == PARENTHESE_OPEN)
			return (PARENTHESE_OPEN);
		i++;
	}
	return (PARENTHESE_CLOSE);
}

int		check_parenthese_char(char c)
{
	int	i;

	i = 0;
	while (i < MAX_PARENTHESE)
	{
		if (g_parenthese[i].c_open == c || g_parenthese[i].c_close == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_parentheses_state(char c)
{
	t_parenthese	*p;
	int				i;
	int				global_state;

	i = 0;
	global_state = check_parentheses();
	while (i < MAX_PARENTHESE)
	{
		p = g_parenthese + i;
		if (p->state == PARENTHESE_CLOSE && c == p->c_open)
		{
			if (global_state == PARENTHESE_CLOSE)
				p->state = PARENTHESE_OPEN;
			return ;
		}
		if (p->state == PARENTHESE_OPEN && c == p->c_close)
		{
			p->state = PARENTHESE_CLOSE;
			return ;
		}
		i++;
	}
}
