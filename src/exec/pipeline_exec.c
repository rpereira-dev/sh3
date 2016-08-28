/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_pipeline_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 08:21:47 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/21 14:51:59 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static t_list	*exec_first_cmd(t_env *env, t_list *cmds, int fds[][2])
{
	t_cmd	*cmd;

	cmd = (t_cmd*)cmds->content;
	pipe(fds[0]);
	if (ft_fork_cmd(env, cmd) == 0)
	{
		handle_pipe(fds[0], PIPE_OUT, PIPE_IN, FD_STDOUT);
		exec_cmd(env, cmd);
		exit(EXIT_SUCCESS);
	}
	return (cmds->next);
}

static t_list	*exec_last_cmd(t_env *env, t_list *cmds, int fds[][2])
{
	t_cmd	*cmd;

	cmd = (t_cmd*)cmds->content;
	if (ft_fork_cmd(env, cmd) == 0)
	{
		handle_pipe(fds[cmd->id - 1], PIPE_IN, PIPE_OUT, FD_STDIN);
		exec_cmd(env, cmd);
		exit(EXIT_SUCCESS);
	}
	close_pipe(fds[cmd->id - 1]);
	return (NULL);
}

static t_list	*exec_middle_cmd(t_env *env, t_list *cmds, int fds[][2])
{
	t_cmd	*cmd;

	while (cmds->next != NULL)
	{
		cmd = (t_cmd*)cmds->content;
		pipe(fds[cmd->id]);
		if (ft_fork_cmd(env, cmd) == 0)
		{
			handle_pipe(fds[cmd->id - 1], PIPE_IN, PIPE_OUT, FD_STDIN);
			handle_pipe(fds[cmd->id], PIPE_OUT, PIPE_IN, FD_STDOUT);
			exec_cmd(env, cmd);
			exit(EXIT_SUCCESS);
		}
		close_pipe(fds[cmd->id - 1]);
		cmds = cmds->next;
	}
	return (cmds);
}

static void		wait_commands(t_list *cmds)
{
	t_cmd	*cmd;
	int		state;

	while (cmds != NULL)
	{
		state = 0;
		cmd = (t_cmd*)cmds->content;
		waitpid(cmd->pid, &state, 0);
		handle_exited_state(cmd, state);
		cmds = cmds->next;
	}
}

int				exec_pipeline(t_env *env, t_list *cmds, int pipes)
{
	t_list	*command;
	int		fds[pipes][2];

	command = cmds;
	command = exec_first_cmd(env, command, fds);
	command = exec_middle_cmd(env, command, fds);
	command = exec_last_cmd(env, command, fds);
	wait_commands(cmds);
	return (SH3_OK);
}
