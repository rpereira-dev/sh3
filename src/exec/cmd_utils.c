/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_cmd_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:49:52 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/21 14:59:31 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	free_cmd(t_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	free_strsplit(cmd->args);
	free(cmd);
}

t_cmd	new_cmd(void)
{
	t_cmd	cmd;

	cmd.args = NULL;
	cmd.file_in = NULL;
	cmd.file_out = NULL;
	cmd.pid = 0;
	cmd.id = 0;
	cmd.redirection = REDIR_NONE;
	return (cmd);
}
