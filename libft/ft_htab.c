/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 21:11:24 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 19:43:46 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_htab_hash(char *str, size_t size)
{
	size_t	hash;
	int		c;

	if (str == NULL)
		return (0);
	hash = 5381;
	while ((c = *str) != '\0')
	{
		hash = ((hash << 5) + hash) + c;
		str++;
	}
	return (hash % size);
}

void		ft_htab_insert(t_htab *tab, char *key, void *data, size_t data_size)
{
	t_list		*lst;
	t_htab_elem	elem;
	size_t		hash;

	hash = ft_htab_hash(key, tab->size);
	elem.index = hash;
	elem.key = ft_strdup(key);
	if ((elem.content = malloc(data_size)) == NULL)
		return ;
	ft_memcpy(elem.content, data, data_size);
	if ((lst = ft_lstnew(&elem, sizeof(t_htab_elem))) == NULL)
		return ;
	if (tab->elems[hash] != NULL)
		ft_lstadd(&(tab->elems[hash]), lst);
	else
		tab->elems[hash] = lst;
}

t_htab		*ft_htab_new(size_t size)
{
	t_htab	*tab;
	size_t	i;

	i = 0;
	tab = (t_htab*)malloc(sizeof(t_htab));
	if (tab == NULL)
		return (NULL);
	tab->size = size;
	tab->elems = (t_list**)malloc(sizeof(t_list*) * size);
	while (i < size)
	{
		tab->elems[i] = NULL;
		i++;
	}
	return (tab);
}

void		ft_htab_free(t_htab *tab)
{
	t_htab_elem	*elem;
	size_t		i;
	t_list		*tmp;
	t_list		*tmp2;

	if (tab == NULL)
		return ;
	i = 0;
	while (i < tab->size)
	{
		tmp = tab->elems[i];
		while (tmp != NULL)
		{
			elem = tmp->content;
			free(elem->content);
			free(elem->key);
			free(elem);
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
		i++;
	}
	free(tab);
}

t_htab_elem	*ft_htab_get(t_htab *tab, char *key)
{
	t_list		*lst;
	t_htab_elem	*elem;
	size_t		hash;

	if (tab == NULL)
		return (NULL);
	hash = ft_htab_hash(key, tab->size);
	if ((lst = tab->elems[hash]) == NULL)
		return (NULL);
	elem = lst->content;
	while (ft_strcmp(elem->key, key) != 0)
	{
		if ((lst = lst->next) == NULL)
			return (NULL);
		elem = lst->content;
	}
	if (lst != NULL)
		return (elem);
	return (NULL);
}
