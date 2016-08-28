/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_ctrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 14:49:53 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 20:22:24 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int	handle_k_ctrl_d(void)
{
	close(0);
	return (K_CTRL_D);
}

int	handle_k_ctrl_u(void)
{
	int	total;

	total = g_line->c_chars - g_line->index;
	while (total--)
		handle_k_right();
	total = g_line->c_chars;
	while (total--)
		handle_k_backspace();
	ft_bzero(g_line, sizeof(t_line));
	g_line->chars = NULL;
	return (K_CTRL_U);
}
