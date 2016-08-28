/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:39:55 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 17:22:32 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (s1 == s2);
	i = 0;
	if (n == 0)
		return (1);
	while (*(s1 + i) == *(s2 + i) && i < n - 1)
	{
		if (*(s1 + i) == '\0')
			return (1);
		i++;
	}
	return (*(s1 + i) == *(s2 + i) ? 1 : 0);
}
