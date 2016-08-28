/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:06:36 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:25:38 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

char	ft_char_at(t_char *c, int len, int index)
{
	char	*str;
	char	ch;

	if (c == NULL || index > len)
		return (-1);
	str = ft_chars_to_str(c, len);
	ch = str[index];
	free(str);
	return (ch);
}
