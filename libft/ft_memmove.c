/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:44:50 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 18:20:39 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned int	i;

	if (src == NULL || dest == NULL)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < len)
		{
			*((char*)dest + i) = *((char*)src + i);
			i++;
		}
	}
	else
	{
		while (len--)
			*((char*)dest + len) = *((char*)src + len);
	}
	return (dest);
}
