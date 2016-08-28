/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:20:27 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/21 15:00:20 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	do_env(t_env *env)
{
	t_list	*tmp;
	t_var	*var;

	tmp = env->environ;
	if (tmp == NULL)
		ft_log(I_WARNING, "environment is empty", NULL);
	while (tmp != NULL)
	{
		var = tmp->content;
		ft_putstr(var->name);
		ft_putstr("=");
		ft_putendl(var->content != NULL ? var->content : "(null)");
		tmp = tmp->next;
	}
}

void	do_setenv(t_env *env, char **args)
{
	if (args == NULL || *args == NULL)
		ft_log(I_WARNING, "usage: setenv [NAME] {VALUE}", NULL);
	else
		set_env_var(env, *args, *(args + 1));
}

void	do_unsetenv(t_env *env, char **args)
{
	if (args == NULL || *args == NULL)
		ft_log(I_WARNING, "usage: unsetenv [NAME]", NULL);
	else
		remove_env_var(env, *args, 1);
}

void	do_cpenv(t_env *env, char **args)
{
	t_var	*var;

	if (args == NULL || *args == NULL || *(args + 1) == NULL)
		ft_log(I_WARNING, "usage: cpenv [NAME] [DEST]", NULL);
	else
	{
		var = get_env_var(env, *args, 1);
		if (var != NULL)
			set_env_var(env, *(args + 1), var->content);
	}
}
