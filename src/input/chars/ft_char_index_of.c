/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_index_of.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 14:45:11 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 10:06:58 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

int	ft_chars_last_index_of(t_char *chars, char c)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (chars != NULL)
	{
		if (chars->c == c)
			return (i);
		chars = chars->next;
		i++;
	}
	return (index);
}

int	ft_chars_index_of(t_char *chars, char c)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (chars != NULL)
	{
		if (chars->c == c)
			index = i;
		chars = chars->next;
		i++;
	}
	return (index);
}

int	ft_chars_index_of_from(t_char *chars, char c, int from)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (chars != NULL && i < from)
	{
		if (chars->c == c)
			index = i;
		chars = chars->next;
		i++;
	}
	return (index);
}

int	ft_chars_last_index_of_from(t_char *chars, char c, int from)
{
	int	index;
	int	i;

	while (chars != NULL && from > 0)
	{
		chars = chars->next;
		from--;
	}
	index = -1;
	i = 0;
	while (chars != NULL)
	{
		if (chars->c == c)
			return (i);
		chars = chars->next;
		i++;
	}
	return (index);
}
