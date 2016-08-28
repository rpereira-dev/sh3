/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 11:11:06 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 14:36:11 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int			handle_k_left(void)
{
	if (g_line->x_cur > 0)
	{
		ft_tputs("le");
		g_line->x_cur--;
		g_line->index--;
		return (K_LEFT);
	}
	return (K_LEFT);
}

int			handle_k_right(void)
{
	struct winsize	ws;

	if (g_line->index >= g_line->c_chars)
		return (K_RIGHT);
	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return (K_RIGHT);
	if ((g_line->x_cur + g_line->prompt_len + 2) % ws.ws_col == 0)
		write(1, "\n", 1);
	else
		ft_tputs("nd");
	g_line->index++;
	g_line->x_cur++;
	return (K_RIGHT);
}
