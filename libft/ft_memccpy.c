/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:12:07 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 17:45:28 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	uc = (unsigned char)c;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((unsigned char*)src)[i] == uc)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
