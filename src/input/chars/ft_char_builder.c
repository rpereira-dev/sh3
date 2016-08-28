/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 13:04:26 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/29 13:15:38 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

t_char	*ft_char_build_from_str(char *str)
{
	t_char	*new;
	int		i;

	new = NULL;
	i = 0;
	while (str[i])
	{
		ft_char_add(&new, ft_char_new(str[i]));
		i++;
	}
	return (new);
}
