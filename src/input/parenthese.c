/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 10:18:47 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 15:57:38 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_parenthese_iter(void (*f)(t_parenthese *))
{
	int	i;

	i = 0;
	while (i < MAX_PARENTHESE)
	{
		f(g_parenthese + i);
		i++;
	}
}

void	print_parenthese(t_parenthese *p)
{
	int	len;

	if (p->state)
	{
		len = ft_strlen(p->name);
		write(1, p->name, len);
		write(1, " ", 1);
		g_line->prompt_len = len + 1;
	}
}

void	init_parenthese(t_parenthese *p)
{
	p->state = PARENTHESE_CLOSE;
}
