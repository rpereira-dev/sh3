/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_env_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:26:33 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/29 13:24:05 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	save_env_var(t_env *env, char **environ)
{
	char	*buff;
	int		namlen;
	int		i;

	while (*environ != NULL)
	{
		namlen = 0;
		i = 0;
		while ((*environ)[namlen] != '=' && (*environ)[namlen])
			namlen++;
		if ((buff = ft_strnew(namlen)) != NULL)
		{
			while (i < namlen)
			{
				buff[i] = (*environ)[i];
				i++;
			}
			add_env_var(env, buff, *environ + namlen + 1);
			free(buff);
		}
		environ = environ + 1;
	}
}

char	**rebuild_env(t_env *env)
{
	char	**args;
	t_list	*tmp;
	t_var	*var;
	int		i;

	args = (char**)malloc(sizeof(char*) * (ft_lstsize(env->environ) + 1));
	if (args == NULL)
		return (NULL);
	i = 0;
	tmp = env->environ;
	while (tmp != NULL)
	{
		var = tmp->content;
		args[i] = ft_strnew(ft_strlen(var->content) + ft_strlen(var->name) + 1);
		ft_strcat(args[i], var->name);
		ft_strcat(args[i], "=");
		ft_strcat(args[i], var->content);
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}
