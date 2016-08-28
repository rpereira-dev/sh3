/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:25:02 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/29 13:16:40 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_builtin	g_builtin[] =
{
	{"cd", do_cd},
	{"exit", do_exit},
	{"env", do_env},
	{"setenv", do_setenv},
	{"unsetenv", do_unsetenv},
	{"cpenv", do_cpenv},
	{NULL, NULL}
};

void	do_exit(void)
{
	ft_putstr("exit\n");
	exit(EXIT_SUCCESS);
}

int		do_builtin(t_env *env, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (g_builtin[i].name != NULL)
	{
		if (ft_strcmp(g_builtin[i].name, *(cmd->args)) == 0)
		{
			g_builtin[i].do_builtin(env, cmd->args + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_cat(char *file, int dst_fd)
{
	char	buffer[8192];
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY)) == -1)
		return ;
	while ((ret = read(fd, buffer, 8191)) > 0)
	{
		buffer[ret] = 0;
		ft_putstr_fd(buffer, dst_fd);
	}
	close(fd);
}

void	ft_help(void)
{
	ft_cat("~/.sh3_helper", 1);
}
