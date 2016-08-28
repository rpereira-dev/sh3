/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:17:26 by rpereira          #+#    #+#             */
/*   Updated: 2015/01/20 09:05:18 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	*alst = NULL;
}
