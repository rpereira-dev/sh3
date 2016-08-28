/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:49:50 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 17:38:44 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_env		*get_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
	{
		env = (t_env*)ft_memalloc(sizeof(t_env));
		if (env == NULL)
		{
			ft_log(I_ERROR, "Not enough memory", NULL);
			exit(EXIT_FAILURE);
		}
	}
	return (env);
}

void		free_env(t_env *env)
{
	t_var	*var;
	t_list	*tmp;

	ft_htab_free(env->bins);
	env->bins = NULL;
	tmp = env->environ;
	while (tmp != NULL)
	{
		var = tmp->content;
		free(var->name);
		free(var->content);
		free(var);
		tmp = tmp->next;
		free(env->environ);
		env->environ = tmp;
	}
}

static void	save_tree_path(void *e, t_htab_elem *elem)
{
	t_env	*env;

	env = (t_env*)e;
	btree_insert_data(&(env->bins_tree), elem->key, ft_void_cmp);
}

void		init_env(t_env *env, char **environ)
{
	ft_bzero(&(env->data), sizeof(t_env_data));
	env->data.stdin_fd = 0;
	env->data.stdout_fd = 1;
	env->state = 0;
	if (environ == NULL || *environ == NULL)
		ft_log(I_WARNING, "Received NULL environment", NULL);
	env->environ = NULL;
	env->bins = ft_htab_new(10000);
	if (env->bins == NULL)
	{
		ft_log(I_ERROR, "Memory error, stoping shell", NULL);
		exit(0);
	}
	save_env_var(env, environ);
	fill_htab(env);
	ft_htab_iter(env->bins, env, save_tree_path);
}
