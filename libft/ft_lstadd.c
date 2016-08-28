/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:20:15 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 09:49:32 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *elem)
{
	if (elem->content == NULL)
		return ;
	if (alst != NULL)
	{
		if (*alst != NULL)
		{
			elem->next = *alst;
			(*alst)->prev = elem;
		}
		*alst = elem;
	}
}
