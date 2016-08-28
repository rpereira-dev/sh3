/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_ncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 08:46:00 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 08:58:46 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

int	ft_chars_ncmp(t_char *c1, t_char *c2, int n)
{
	int	i;

	if (c1 == NULL)
		return (c2 == NULL);
	if (c2 == NULL)
		return (c1->c);
	i = 0;
	while (i < n && c1->c == c2->c && c1 != NULL && c2 != NULL)
	{
		c1 = c1->next;
		c2 = c2->next;
		i++;
	}
	if (c1 == NULL && c2 == NULL)
		return (0);
	return (c2->c - c1->c);
}
