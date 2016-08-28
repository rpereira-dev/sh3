/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:02:19 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 08:57:46 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

void	ft_char_push(t_char **lst, t_char *ch)
{
	t_char	*tmp;

	if (lst == NULL || ch == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = ch;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ch;
}
