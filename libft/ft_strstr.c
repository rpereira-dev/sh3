/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 09:29:40 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 18:46:09 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return ((char*)s1);
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j])
			j++;
		if (!(s2[j]))
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
