/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:33:46 by rpereira          #+#    #+#             */
/*   Updated: 2014/12/29 16:44:31 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
