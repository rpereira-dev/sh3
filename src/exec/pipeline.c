/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 15:53:41 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:59:33 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	close_pipe(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
}

void	handle_pipe(int fds[2], int to_close, int to_dup, int dup_dir)
{
	close(fds[to_close]);
	dup2(fds[to_dup], dup_dir);
}

void	prepare_command(t_cmd *cmd)
{
	int	fd;

	if (cmd->file_in != NULL)
	{
		fd = open_file(cmd->file_in, O_RDONLY);
		if (fd != -1)
			dup2(fd, FD_STDIN);
	}
	if (cmd->file_out != NULL)
	{
		if (cmd->redirection == REDIR_OUT_APPEND)
			fd = open_file(cmd->file_out, O_RDWR | O_APPEND | O_CREAT);
		else
			fd = open_file(cmd->file_out, O_RDWR | O_TRUNC | O_CREAT);
		if (fd != -1)
			dup2(fd, FD_STDOUT);
	}
}
