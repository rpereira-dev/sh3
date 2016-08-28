/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:00:13 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 15:16:14 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

char	*g_copy = NULL;

int	handle_k_ctrl_p(void)
{
	handle_none(g_copy, ft_strlen(g_copy));
	return (K_CTRL_P);
}

int	handle_k_ctrl_k(void)
{
	char	*str;

	if ((str = ft_chars_to_str(g_line->chars, g_line->c_chars)) == NULL)
		return (K_CTRL_K);
	if (g_copy != NULL)
		free(g_copy);
	g_copy = ft_strdup(str + g_line->index);
	free(str);
	while (g_line->index != g_line->c_chars)
		handle_k_delete();
	return (K_CTRL_K);
}

int	handle_k_ctrl_h(void)
{
	char	*str;
	int		total;

	if ((str = ft_chars_to_str(g_line->chars, g_line->c_chars)) == NULL)
		return (K_CTRL_L);
	if (g_copy != NULL)
		free(g_copy);
	g_copy = ft_strndup(str + g_line->index - g_line->x_cur, g_line->x_cur);
	free(str);
	total = g_line->x_cur;
	while (total > 0)
	{
		handle_k_backspace();
		total--;
	}
	return (K_CTRL_L);
}
