/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_lst_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 11:05:34 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:11:25 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

char	*ft_chars_to_str(t_char *lst, int len)
{
	char	*str;

	if ((str = (char*)ft_memalloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = 0;
	len--;
	while (len >= 0)
	{
		str[len] = lst->c;
		lst = lst->next;
		len--;
	}
	return (str);
}
