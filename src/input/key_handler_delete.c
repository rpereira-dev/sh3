/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 11:03:30 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 11:56:08 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int	handle_k_delete(void)
{
	int		index;
	char	c;

	if (g_line->index >= g_line->c_chars)
		return (K_DELETE);
	ft_tputs("sc");
	index = g_line->index;
	c = ft_char_at(g_line->chars, g_line->c_chars, g_line->index);
	check_parentheses_state(c);
	ft_chars_write_from_index(g_line->chars, g_line->c_chars, index + 1);
	write(1, " ", 1);
	ft_char_remove_index(&(g_line->chars), g_line->c_chars - index - 1);
	g_line->c_chars--;
	ft_tputs("rc");
	return (K_DELETE);
}
