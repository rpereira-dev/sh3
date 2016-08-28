/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/11 10:52:44 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/01 17:01:09 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		length;
	int		i;

	length = ft_strlen(src);
	i = 0;
	if ((ptr = ft_strnew(length)) == NULL)
		return (NULL);
	while (i < length)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[length] = '\0';
	return (ptr);
}

char	*ft_strndup(const char *src, int length)
{
	char	*ptr;
	int		i;

	i = 0;
	if ((ptr = ft_strnew(length)) == NULL)
		return (NULL);
	while (i < length)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[length] = '\0';
	return (ptr);
}
