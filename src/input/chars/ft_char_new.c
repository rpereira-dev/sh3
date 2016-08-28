/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 10:58:10 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/01 16:18:41 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

t_char	*ft_char_new(char c)
{
	t_char	*ch;

	if ((ch = (t_char*)malloc(sizeof(t_char))) == NULL)
		return (NULL);
	ch->c = c;
	ch->next = NULL;
	return (ch);
}
