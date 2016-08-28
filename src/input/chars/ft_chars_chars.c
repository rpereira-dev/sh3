/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 08:47:26 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 10:06:38 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

int	ft_chars_chars(t_char *c1, t_char *c2)
{
	char	*s1;
	char	*s2;
	size_t	r;

	if (c1 == NULL)
		return (c2 == NULL);
	if (c2 == NULL)
		return (c1->c);
	s1 = ft_chars_to_str(c1, ft_chars_len(c1));
	s2 = ft_chars_to_str(c2, ft_chars_len(c2));
	r = (size_t)ft_strstr(s1, s2);
	free(s1);
	free(s2);
	return (!r);
}
