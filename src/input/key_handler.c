/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 12:11:45 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:34:09 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	handle_char(char ch)
{
	t_char	*c;

	c = ft_char_new(ch);
	write(1, &ch, 1);
	check_parentheses_state(ch);
	ft_chars_write_from_index(g_line->chars, g_line->c_chars, g_line->index);
	ft_char_add_index(&(g_line->chars), c, g_line->c_chars - g_line->index);
}

static void	replace_cursor(void)
{
	struct winsize	ws;
	int				total;

	total = g_line->c_chars - g_line->index;
	if (g_line->index != g_line->c_chars && ioctl(0, TIOCGWINSZ, &ws) != -1)
	{
		if ((g_line->c_chars + g_line->prompt_len + 1) % ws.ws_col == 0)
		{
			total--;
		}
	}
	while (total > 0)
	{
		ft_tputs("le");
		total = total - 1;
	}
}

int			handle_none(char *buffer, int len)
{
	int	i;

	if (buffer == NULL)
		return (K_NONE);
	i = 0;
	while (i < len && buffer[i])
	{
		if (!ft_isascii(buffer[i]))
			buffer[i] = '?';
		handle_char(buffer[i]);
		replace_cursor();
		g_line->c_chars++;
		g_line->index++;
		g_line->x_cur++;
		i++;
	}
	return (K_NONE);
}
