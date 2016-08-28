/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 09:05:34 by rpereira          #+#    #+#             */
/*   Updated: 2015/01/20 15:53:55 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst, void (*ft_free)())
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		if (ft_free != NULL)
			ft_free(tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
		tmp2 = NULL;
	}
}
