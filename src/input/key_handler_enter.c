/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_enter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 16:34:12 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 12:18:36 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	replace_cursor(void)
{
	struct winsize	ws;
	int				total;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return ;
	total = g_line->c_chars - g_line->index + g_line->prompt_len;
	if (total < ws.ws_col)
		return ;
	total = total / ws.ws_col;
	while (total > 0)
	{
		write(1, "\n", 1);
		total--;
	}
}

static void	insert_newline(void)
{
	g_line->index = g_line->c_chars;
	handle_none("\n", 1);
	ft_parenthese_iter(print_parenthese);
	write(1, PARENTHESE_PROMPT, PARENTHESE_PROMPT_LEN);
	g_line->prompt_len += PARENTHESE_PROMPT_LEN;
	g_line->x_cur = 0;
}

int			handle_k_enter(void)
{
	replace_cursor();
	if (check_parentheses() == PARENTHESE_CLOSE)
	{
		save_line();
		return (K_ENTER);
	}
	insert_newline();
	return (K_NONE);
}
