/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:07:36 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/21 15:00:10 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_chdir_to(t_env *env, char *path)
{
	char	buffer[1024];

	ft_bzero(buffer, 1024);
	getcwd(buffer, 1024);
	if (chdir(path) == -1)
		ft_log(I_ERROR, "An error occured while changing to: ", path);
	else
	{
		set_env_var(env, "OLDPWD", buffer);
		ft_bzero(buffer, 1024);
		getcwd(buffer, 1024);
		set_env_var(env, "PWD", buffer);
	}
}

void	ft_chdir(t_env *env, char *path)
{
	char		buffer[1024];
	struct stat	s;

	ft_bzero(buffer, 1024);
	if (path == NULL)
	{
		ft_log(I_ERROR, "An error occured while performing: cd", NULL);
		return ;
	}
	if (!file_is_accessible(env, path, E_EXIST | E_READ))
		return ;
	else if (stat(path, &s) && !S_ISDIR(s.st_mode))
		ft_log(I_WARNING, "Not a directory: ", path);
	else
		ft_chdir_to(env, path);
}

void	do_cd(t_env *env, char **args)
{
	t_var	*var;

	if (*args == NULL)
	{
		var = get_env_var(env, "HOME", 1);
		if (var == NULL || var->content == NULL)
			return ;
		ft_chdir(env, var->content);
	}
	else if (ft_strcmp(*args, "-") == 0)
	{
		var = get_env_var(env, "OLDPWD", 1);
		if (var == NULL || var->content == NULL)
			return ;
		ft_chdir(env, var->content);
	}
	else
		ft_chdir(env, *args);
}
