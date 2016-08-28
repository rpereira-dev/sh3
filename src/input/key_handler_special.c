/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_special.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 09:39:20 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:07:00 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int	handle_k_home(void)
{
	if (g_line->chars == NULL)
		return (K_HOME);
	while (g_line->x_cur > 0)
	{
		handle_k_left();
	}
	return (K_HOME);
}

int	handle_k_end(void)
{
	if (g_line->chars == NULL)
		return (K_END);
	while (g_line->index != g_line->c_chars)
		handle_k_right();
	return (K_END);
}

int	handle_k_ctrl_l(void)
{
	ft_tputs("cl");
	//ioctl(0, TIOCSTI, "\n");
	return (K_CTRL_L);
}

int	handle_k_nothing(void)
{
	return (-1);
}
