/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_backspace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 12:29:23 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 10:53:32 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	remove_char_backspace(void)
{
	ft_tputs("sc");
	ft_tputs("le");
	ft_chars_write_from_index(g_line->chars, g_line->c_chars, g_line->index);
	ft_char_remove_index(&(g_line->chars), g_line->c_chars - g_line->index);
	write(1, " ", 1);
	ft_tputs("rc");
	handle_k_left();
	g_line->c_chars--;
}

int			handle_k_backspace(void)
{
	char	c;

	if (g_line->x_cur > 0 && g_line->c_chars > 0)
	{
		c = ft_char_at(g_line->chars, g_line->c_chars, g_line->index - 1);
		check_parentheses_state(c);
		remove_char_backspace();
	}
	return (K_BACKSPACE);
}
