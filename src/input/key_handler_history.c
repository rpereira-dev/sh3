/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 09:57:53 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 20:09:29 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	clear_line(void)
{
	int	total;

	total = g_line->index;
	while (total > 0)
	{
		ft_tputs("le");
		total--;
	}
	total = g_line->c_chars;
	while (total > 0)
	{
		write(1, " ", 1);
		total--;
	}
	total = g_line->c_chars;
	while (total > 0)
	{
		ft_tputs("le");
		total--;
	}
}

static void	reset_line(t_line **ptr)
{
	int	index;

	g_line = *ptr;
	g_line->index = g_line->c_chars;
	index = ft_chars_last_index_of(g_line->chars, '\n');
	g_line->x_cur = (index == -1) ? g_line->index : index;
	g_line->prompt_len = PROMPT_LEN;
	ft_chars_write(g_line->chars, g_line->c_chars);
}

int			handle_k_up(void)
{
	t_line	**ptr;
	t_list	*node;

	if (g_history_lst != NULL)
	{
		node = g_current_node;
		if (g_current_node == NULL)
			g_current_node = g_history_lst;
		else if (g_current_node->next != NULL)
			g_current_node = g_current_node->next;
		if (node != g_current_node)
		{
			clear_line();
			save_line();
			ptr = (t_line**)g_current_node->content;
			reset_line(ptr);
		}
	}
	return (K_UP);
}

int			handle_k_down(void)
{
	t_line	**ptr;

	if (g_current_node != NULL)
	{
		if (g_current_node->prev != NULL)
		{
			clear_line();
			g_current_node = g_current_node->prev;
			ptr = (t_line**)g_current_node->content;
			reset_line(ptr);
		}
	}
	return (K_DOWN);
}
