/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:54:47 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 17:16:56 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	i;
	int	length;

	if (s == NULL)
		return ;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		s[i] = '\0';
		i++;
	}
}
