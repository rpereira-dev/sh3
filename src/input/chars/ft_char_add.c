/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:01:51 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 08:55:42 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

void	ft_char_add(t_char **lst, t_char *ch)
{
	if (ch == NULL)
		return ;
	if (lst != NULL)
	{
		if (*lst != NULL)
			ch->next = *lst;
		*lst = ch;
	}
}
