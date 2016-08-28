/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidvoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 18:04:16 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/26 18:38:32 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_voidvoid(void *a, void *b)
{
	const char	*s1;
	const char	*s2;

	s1 = (const char*)a;
	s2 = (const char*)b;
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}
