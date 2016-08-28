/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_add_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:03:15 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:12:02 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

void	ft_char_add_index(t_char **lst, t_char *ch, int index)
{
	t_char		*tmp;
	int			i;

	if (lst == NULL || ch == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = ch;
		return ;
	}
	if (index == 0)
	{
		ft_char_add(lst, ch);
		return ;
	}
	i = 0;
	tmp = *lst;
	while (i < index - 1 && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	ch->next = tmp->next;
	tmp->next = ch;
}
