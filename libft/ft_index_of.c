/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:49:41 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/01 16:54:22 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_last_indexof(char *str, char c)
{
	int	index;
	int	i;

	if (str == NULL)
		return (-1);
	index = -1;
	i = 0;
	while (*str)
	{
		if (*str == c)
			index = i;
		i++;
		str++;
	}
	return (index);
}

int	ft_indexof(char *str, char c)
{
	int	index;

	if (str == NULL)
		return (-1);
	index = 0;
	while (*str)
	{
		if (*str == c)
			return (index);
		index++;
		str++;
	}
	return (-1);
}
