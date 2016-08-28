/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 12:08:34 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:11:24 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_line			*g_line = NULL;

t_key_handler	g_key_handler[MAX_KEY] = {
	{{0, 0, 0, 0}, handle_none},
	{{27, 91, 68, 0}, handle_k_left},
	{{27, 91, 65, 0}, handle_k_up},
	{{27, 91, 67, 0}, handle_k_right},
	{{27, 91, 66, 0}, handle_k_down},
	{{127, 0}, handle_k_backspace},
	{{27, 91, 51, 126, 0}, handle_k_delete},
	{{10, 0}, handle_k_enter},
	{{4, 0}, handle_k_ctrl_d},
	{{21, 0}, handle_k_ctrl_u},
	{{'\t', 0}, handle_k_tab},
	{{27, 91, 70, 0}, handle_k_end},
	{{27, 91, 72, 0}, handle_k_home},
	{{27, 91, 49, 59, 50, 70, 0}, handle_k_end},
	{{27, 91, 49, 59, 50, 72, 0}, handle_k_home},
	{{27, 91, 49, 59, 50, 68, 0}, handle_k_shift_left},
	{{27, 91, 49, 59, 50, 67, 0}, handle_k_shift_right},
	{{27, 91, 49, 59, 50, 66, 0}, handle_k_shift_down},
	{{27, 91, 49, 59, 50, 65, 0}, handle_k_shift_up},
	{{11, 0}, handle_k_ctrl_k},
	{{16, 0}, handle_k_ctrl_p},
	{{12, 0}, handle_k_ctrl_l},
	{{8, 0}, handle_k_ctrl_h},
	{{27, 91, 49, 59, 57, 68, 0}, handle_k_left},
	{{27, 91, 49, 59, 57, 65, 0}, handle_k_up},
	{{27, 91, 49, 59, 57, 67, 0}, handle_k_right},
	{{27, 91, 49, 59, 57, 66, 0}, handle_k_down}
};

t_parenthese	g_parenthese[MAX_PARENTHESE] = {
	{'[', ']', {'c', 'r', 'o', 's', 'h', 0, 0, 0}, 0},
	{'{', '}', {'c', 'u', 'r', 's', 'h', 0, 0, 0}, 0},
	{'(', ')', {'s', 'u', 'b', 's', 'h', 0, 0, 0}, 0},
	{'"', '"', {'d', 'q', 'u', 'o', 't', 'e', 0, 0}, 0},
	{'\'', '\'', {'q', 'u', 'o', 't', 'e', 0, 0, 0}, 0},
	{'`', '`', {'b', 'q', 'u', 'o', 't', 'e', 0, 0}, 0}
};
