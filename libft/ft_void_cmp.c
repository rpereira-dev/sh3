/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 18:01:09 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 18:04:12 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_void_cmp(void *a, void *b)
{
	const char	*s1;
	const char	*s2;

	s1 = (const char*)a;
	s2 = (const char*)b;
	return (ft_strcmp(s1, s2));
}
