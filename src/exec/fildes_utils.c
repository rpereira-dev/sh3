/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_fildes_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 19:18:01 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:58:42 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		open_file(char *file, int flags)
{
	int	fd;

	if (file == NULL)
	{
		ft_log(I_WARNING, "Tried to open a NULL file path", NULL);
		return (1);
	}
	fd = open(file, flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		ft_log(I_WARNING, "couldnt open / create file: ", file);
	return (fd);
}

void	save_std_fd(void)
{
	t_env	*env;

	env = get_env();
	env->data.stdin_fd = dup(0);
	env->data.stdout_fd = dup(1);
}

pid_t	ft_fork_cmd(t_env *env, t_cmd *cmd)
{
	int	ret;

	if (cmd == NULL)
		return (-1);
	ret = fork();
	if (ret == -1)
	{
		ft_log(I_ERROR, "Fork error on command: ", *(cmd->args));
		return (-1);
	}
	env->data.process_id = ret;
	cmd->pid = ret;
	return (ret);
}
