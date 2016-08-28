/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_redirections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:13:43 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 17:01:58 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_heredoc_prompt(void)
{
	ft_putstr(C_BBLUE);
	ft_putstr("heredoc ");
	ft_putwc(WC_CLOUD);
	ft_putstr(C_RESET);
	ft_putstr("  ");
}

static int	ft_heredoc(char *end)
{
	char	*line;
	int		fd;

	if ((fd = open_file("/tmp/sh3.tmp", O_WRONLY | O_CREAT | O_TRUNC)) == -1)
		return (0);
	ft_heredoc_prompt();
	while (get_next_line(0, &line) > 0 && ft_strcmp(line, end) != 0)
	{
		ft_putendl_fd(line, fd);
		free(line);
		ft_heredoc_prompt();
	}
	free(line);
	close(fd);
	return (1);
}

static void	register_cmd_redirection(char **args, t_cmd *cmd)
{
	if (ft_strcmp(args[0], ">") == 0)
	{
		cmd->file_out = ft_strdup(args[1]);
		cmd->redirection = REDIR_OUT_TRUNC;
	}
	if (ft_strcmp(args[0], ">>") == 0)
	{
		cmd->file_out = ft_strdup(args[1]);
		cmd->redirection = REDIR_OUT_APPEND;
	}
	if (ft_strcmp(args[0], "<") == 0)
	{
		cmd->file_in = ft_strdup(args[1]);
		cmd->redirection = REDIR_IN_FILE;
	}
	if (ft_strcmp(args[0], "<<") == 0 && ft_heredoc(args[1]))
	{
		cmd->file_in = ft_strdup("/tmp/sh3.tmp");
		cmd->redirection = REDIR_IN_FILE;
	}
}

void		register_cmd_fd(char **args, t_cmd *cmd)
{
	int	i;

	cmd->file_in = NULL;
	cmd->file_out = NULL;
	cmd->redirection = REDIR_NONE;
	i = 0;
	while (args[i])
	{
		register_cmd_redirection(args + i, cmd);
		i++;
	}
}
