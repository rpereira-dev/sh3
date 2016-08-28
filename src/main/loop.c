/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 10:14:54 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 10:48:50 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	end_commands(t_env *env)
{
	dup2(env->data.stdin_fd, 0);
	dup2(env->data.stdout_fd, 1);
}

static int	do_cmd(t_env *env, t_list *cmds, int count)
{
	save_std_fd();
	if (count == 1)
		return (do_unpipe_cmd(env, (t_cmd*)cmds->content));
	return (exec_pipeline(env, cmds, count - 1));
}

static void	free_commands(t_list *cmds)
{
	t_list	*lst;
	t_cmd	*cmd;

	lst = (t_list*)cmds->content;
	while (lst != NULL)
	{
		cmd = (t_cmd*)lst->content;
		free_strsplit(cmd->args);
		if (cmd->file_in != NULL)
			free(cmd->file_in);
		if (cmd->file_out != NULL)
			free(cmd->file_out);
		free(cmd);
		lst = lst->next;
	}
}

static void	exec_commands(t_env *env, t_list *cmds)
{
	t_list	*cmd;
	t_list	*prev;

	while (cmds != NULL)
	{
		save_std_fd();
		cmd = cmds->content;
		do_cmd(env, cmd, ft_lstsize(cmd));
		end_commands(env);
		prev = cmds;
		cmds = cmds->next;
		free_commands(prev);
		free(prev->content);
		free(prev);
	}
}

void		shell_loop(t_env *env)
{
	t_list	*cmds;
	char	*line;

	line = NULL;
	while (prompt(env, &line) > 0)
	{
		env->state = SH3_OK;
		if (line != NULL)
		{
			cmds = ft_parse_input(line);
			if (env->state != SH3_ERR)
			{
				signal(SIGINT, catch_process_interupt);
				exec_commands(env, cmds);
			}
			free(line);
		}
	}
}
