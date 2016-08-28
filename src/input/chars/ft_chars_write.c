/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 13:04:23 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:25:19 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

void	ft_chars_write_from_index(t_char *lst, int len, int index)
{
	char	*str;

	if (index > len)
		index = len;
	str = ft_chars_to_str(lst, len);
	write(1, str + index, len - index);
	free(str);
}

void	ft_chars_write_to_index(t_char *lst, int len, int index)
{
	char	*str;

	if (index > len)
		index = len;
	str = ft_chars_to_str(lst, len);
	write(1, str, index);
	free(str);
}

void	ft_chars_write(t_char *lst, int len)
{
	char	*str;

	str = ft_chars_to_str(lst, len);
	write(1, str, len);
	free(str);
}
