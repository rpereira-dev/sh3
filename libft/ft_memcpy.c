/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:41:51 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/30 12:33:13 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest == NULL || src == NULL)
		return (dest);
	i = 0;
	while (i < n)
	{
		*((char*)dest + i) = *(char*)(src + i);
		i++;
	}
	return (dest);
}
