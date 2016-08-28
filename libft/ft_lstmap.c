/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:22:43 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 18:17:54 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*i;

	if (f == NULL)
		return (NULL);
	ret = f(lst);
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	i = lst->next;
	while (i != NULL)
	{
		tmp->next = f(i);
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
		i = i->next;
	}
	return (ret);
}
