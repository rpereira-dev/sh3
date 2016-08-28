/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/11 10:52:44 by rpereira          #+#    #+#             */
/*   Updated: 2015/01/19 17:02:04 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	if ((ptr = ft_strnew(n)) == NULL)
		return (NULL);
	while (i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[n] = '\0';
	return (ptr);
}
