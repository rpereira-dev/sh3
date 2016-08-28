/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:50:08 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:23:09 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	create_config_file(int fd)
{
	ft_log(I_OK, "Creating config file", NULL);
	ft_putendl_fd("# ft_minishell2 config file", fd);
	ft_putendl_fd("#", fd);
	ft_putendl_fd("# alias example:", fd);
	ft_putendl_fd("alias \"ls -la\"=l", fd);
}

static void	read_config_file(t_env *env, int fd)
{
	(void)env;
	(void)fd;
}

void		init_config(t_env *env)
{
	t_var	*home;
	char	*path;
	int		fd;
	int		new;

	home = get_env_var(env, "HOME", 0);
	if (home == NULL || home->content == NULL)
	{
		ft_log(I_WARNING, "config file (.sh3) not found", NULL);
		return ;
	}
	path = ft_strjoin(home->content, "/.sh3");
	if (path == NULL)
		return ;
	new = access(path, F_OK) == -1;
	fd = open(path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (new)
		create_config_file(fd);
	read_config_file(env, fd);
	close(fd);
	free(path);
}
