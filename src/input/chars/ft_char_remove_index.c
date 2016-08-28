/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:46:59 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:25:30 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

static void	ft_char_remove_index_(t_char **lst, int index)
{
	t_char	*tmp;
	t_char	*prev;

	tmp = *lst;
	prev = NULL;
	while (index > 0)
	{
		index--;
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev == NULL)
		*lst = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp);
}

void		ft_char_remove_index(t_char **lst, int index)
{
	if (lst == NULL || *lst == NULL)
		return ;
	if (index == 0)
	{
		ft_char_remove_first(lst);
		return ;
	}
	if (index >= ft_chars_len(*lst))
	{
		ft_char_remove_last(lst);
		return ;
	}
	ft_char_remove_index_(lst, index);
}
