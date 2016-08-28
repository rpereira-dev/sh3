/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 08:39:00 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/11 18:09:57 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	if (s == NULL)
		return (NULL);
	tmp = (char*)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (tmp + i);
		i++;
	}
	if ((char)c == '\0')
		return (tmp + i);
	return (NULL);
}
