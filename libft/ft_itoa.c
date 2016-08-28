/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:49:24 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 18:35:44 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int	size;

	size = (n < 0) ? 1 : 0;
	while (n > 1 || n < -1)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

static char	*ft_itoa_rev(char *str)
{
	char	*begin;
	char	tmp;
	int		length;
	int		i;

	begin = str;
	str = (*str == '-') ? str + 1 : str;
	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = tmp;
		i++;
	}
	return (begin);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if ((str = (char*)malloc(sizeof(char) * (ft_itoa_size(n) + 1))) == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (n != 0)
	{
		str[i] = ABS(n % 10) + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
	return (ft_itoa_rev(str));
}
