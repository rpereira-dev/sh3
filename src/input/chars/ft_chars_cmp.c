/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 08:43:58 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 08:59:03 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

int	ft_chars_cmp(t_char *c1, t_char *c2)
{
	if (c1 == NULL)
		return (c2 == NULL);
	if (c2 == NULL)
		return (c1->c);
	while (c1->c == c2->c && c1 != NULL && c2 != NULL)
	{
		c1 = c1->next;
		c2 = c2->next;
	}
	if (c1 == NULL && c2 == NULL)
		return (0);
	return (c2->c - c1->c);
}
