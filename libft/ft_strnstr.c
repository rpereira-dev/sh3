/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:18:52 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 18:46:19 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return ((char*)s1);
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && i + j < n)
				j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
			i += j;
		}
		i++;
	}
	return (NULL);
}
