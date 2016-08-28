/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 12:56:12 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 17:52:57 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_htab_count_elem(t_htab *tab)
{
	t_htab_elem	*elem;
	t_list		*maillon;
	size_t		size;
	size_t		i;

	if (tab == NULL)
		return (0);
	size = 0;
	i = 0;
	while (i < tab->size)
	{
		maillon = tab->elems[i];
		while (maillon != NULL)
		{
			elem = maillon->content;
			if (elem != NULL)
				size = size + 1;
			maillon = maillon->next;
		}
		i++;
	}
	return (size);
}

void	ft_htab_print_content(t_htab *tab)
{
	t_htab_elem	*elem;
	t_list		*maillon;
	size_t		i;

	if (tab == NULL)
		return ;
	i = 0;
	while (i < tab->size)
	{
		maillon = tab->elems[i];
		while (maillon != NULL)
		{
			elem = maillon->content;
			if (elem != NULL && elem->content != NULL)
			{
				ft_putstr(elem->key);
				write(1, "=", 1);
				ft_putendl(elem->content);
			}
			maillon = maillon->next;
		}
		i++;
	}
}

void	ft_htab_iter(t_htab *tab, void *extra, void (*f)(void *, t_htab_elem *))
{
	t_htab_elem	*elem;
	t_list		*maillon;
	size_t		i;

	if (tab == NULL)
		return ;
	i = 0;
	while (i < tab->size)
	{
		maillon = tab->elems[i];
		while (maillon != NULL)
		{
			elem = maillon->content;
			if (elem != NULL && elem->content != NULL)
				f(extra, elem);
			maillon = maillon->next;
		}
		i++;
	}
}
