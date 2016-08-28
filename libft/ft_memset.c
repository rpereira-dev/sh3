/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:53:14 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 18:27:22 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;

	if (b == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*((unsigned char*)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
