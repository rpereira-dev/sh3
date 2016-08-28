/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:40:01 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 10:25:19 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		catch_process_interupt(int signo)
{
	write(1, "\n", 1);
	kill(get_env()->data.process_id, signo);
}

int			file_is_accessible(t_env *env, char *file, int indices)
{
	if (indices & E_EXIST && access(file, F_OK))
	{
		ft_log(I_WARNING, "No such file: ", file);
		env->state = env->state | SH3_ERR;
		return (0);
	}
	if (indices & E_EXEC && access(file, X_OK))
	{
		ft_log(I_ERROR, "You don't have the executable permission: ", file);
		env->state = env->state | SH3_ERR;
		return (0);
	}
	if (indices & E_WRITE && access(file, W_OK))
	{
		ft_log(I_ERROR, "You don't have the write permission: ", file);
		env->state = env->state | SH3_ERR;
		return (0);
	}
	if (indices & E_READ && access(file, R_OK))
	{
		ft_log(I_ERROR, "You don't have the read permission: ", file);
		env->state = env->state | SH3_ERR;
		return (0);
	}
	return (1);
}

static int	get_sig_error(char buffer[], int state)
{
	if (state == SIGINT)
		ft_strcpy(buffer, "interupted");
	else if (state == SIGSEGV)
		ft_strcpy(buffer, "segmentation fault");
	else if (state == SIGBUS)
		ft_strcpy(buffer, "bus error");
	else
		return (0);
	return (1);
}

void		handle_exited_state(t_cmd *cmd, int state)
{
	char	buffer[64];

	if (!WIFSIGNALED(state) || !get_sig_error(buffer, WTERMSIG(state)))
		return ;
	ft_putstr("* process didnt stop properly: ");
	ft_putnbr(cmd->pid);
	ft_putchar('\n');
	ft_putstr(*(cmd->args));
	ft_putstr(" : ");
	ft_putstr(buffer);
	ft_putstr(" [");
	ft_putnbr(state);
	ft_putstr("]\n");
}
