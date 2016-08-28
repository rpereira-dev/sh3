/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 12:06:56 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 11:48:52 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int	handle_k_shift_left(void)
{
	char	*str;

	if (g_line->chars == NULL)
		return (K_SHIFT_LEFT);
	str = ft_chars_to_str(g_line->chars, g_line->c_chars);
	while (g_line->x_cur > 0 && str[g_line->index] != ' ')
		handle_k_left();
	while (g_line->x_cur > 0 && str[g_line->index] == ' ')
		handle_k_left();
	free(str);
	return (K_SHIFT_LEFT);
}

int	handle_k_shift_right(void)
{
	char	*str;

	if (g_line->chars == NULL)
		return (K_SHIFT_RIGHT);
	str = ft_chars_to_str(g_line->chars, g_line->c_chars);
	while (g_line->index < g_line->c_chars && str[g_line->index] != ' ')
		handle_k_right();
	while (g_line->index < g_line->c_chars && str[g_line->index] == ' ')
		handle_k_right();
	free(str);
	return (K_SHIFT_RIGHT);
}

int	handle_k_shift_down(void)
{
	struct winsize	ws;
	int				total;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return (K_SHIFT_DOWN);
	total = MIN(g_line->c_chars - g_line->index, ws.ws_col);
	while (total--)
		handle_k_right();
	return (K_SHIFT_DOWN);
}

int	handle_k_shift_up(void)
{
	struct winsize	ws;
	int				total;

	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return (K_SHIFT_UP);
	total = MIN(g_line->x_cur, ws.ws_col);
	while (total--)
		handle_k_left();
	return (K_SHIFT_UP);
}
