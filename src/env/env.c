/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:26:20 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/29 13:30:22 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_var	new_var(char *name, char *content)
{
	t_var	var;

	var.name = ft_strdup(name);
	var.content = ft_strdup(content);
	return (var);
}

t_var	*get_env_var(t_env *env, char *name, int err)
{
	t_list	*elem;
	t_var	*var;

	elem = env->environ;
	while (elem != NULL)
	{
		var = elem->content;
		if (ft_strcmp(var->name, name) == 0)
			return (var);
		elem = elem->next;
	}
	(err) ? ft_log(I_WARNING, "Could not find variable named: ", name) : 0;
	return (NULL);
}

void	set_env_var(t_env *env, char *name, char *value)
{
	t_list	*elem;
	t_var	*var;

	elem = env->environ;
	while (elem != NULL)
	{
		var = elem->content;
		if (ft_strcmp(var->name, name) == 0)
		{
			free(var->content);
			var->content = ft_strdup(value);
			return ;
		}
		elem = elem->next;
	}
	add_env_var(env, name, value);
}

void	add_env_var(t_env *env, char *name, char *content)
{
	t_var	var;

	var = new_var(name, content);
	ft_lstpush(&(env->environ), ft_lstnew(&var, sizeof(t_var)));
}

void	remove_env_var(t_env *env, char *name, int err)
{
	t_list	*left;
	t_list	*elem;
	t_var	*var;

	elem = env->environ;
	left = elem;
	while (elem != NULL)
	{
		var = elem->content;
		if (ft_strcmp(var->name, name) == 0)
		{
			if (elem != left)
				left->next = elem->next;
			else
				env->environ = env->environ->next;
			free(var->name);
			free(var->content);
			free(var);
			free(elem);
			return ;
		}
		left = elem;
		elem = elem->next;
	}
	(err) ? ft_log(I_WARNING, "Could not find variable named: ", name) : 0;
}
