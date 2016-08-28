/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 19:19:44 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 16:48:57 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_do(char *str, int sign, int in_fraction, int divisor)
{
	double	integer;
	double	fraction;

	integer = 0;
	fraction = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			if (in_fraction && (divisor = divisor * 10))
				fraction = fraction * 10 + (*str - '0');
			else
				integer = integer * 10 + (*str - '0');
		}
		else
		{
			if (!in_fraction && *str != '.')
				break ;
			else
				in_fraction = 1;
		}
		++str;
	}
	return (sign * (integer + fraction / divisor));
}

double			ft_atof(char *str)
{
	int		sign;

	if (str == NULL || !*str)
		return (0);
	sign = 1;
	if (*str == '-')
	{
		++str;
		sign = -1;
	}
	else if (*str == '+')
		++str;
	return (ft_atof_do(str, sign, 0, 1));
}
