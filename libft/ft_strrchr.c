/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:37:31 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/21 11:40:16 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char*)(s + len));
		len--;
	}
	return (NULL);
}
