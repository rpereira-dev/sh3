/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:03:40 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/31 17:14:28 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

void	ft_chars_free(t_char **lst)
{
	t_char	*tmp;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		*lst = tmp;
		tmp = tmp->next;
		free(*lst);
	}
	*lst = NULL;
}
