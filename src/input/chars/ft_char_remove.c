/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:51:35 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 08:57:53 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

void	ft_char_remove_first(t_char **lst)
{
	t_char	*to_free;

	if (lst == NULL || *lst == NULL)
		return ;
	to_free = *lst;
	*lst = (*lst)->next;
	free(to_free);
}

void	ft_char_remove_last(t_char **lst)
{
	t_char	*tmp;
	t_char	*prev;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = *lst;
	prev = NULL;
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	if (prev != NULL)
		prev->next = NULL;
	else
		*lst = NULL;
}
