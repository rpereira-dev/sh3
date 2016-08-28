/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_cmd_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 08:22:56 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 17:22:58 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	do_exec(t_env *env, char *path, t_cmd *cmd)
{
	if (!file_is_accessible(env, path, E_EXIST | E_EXEC))
		return (SH3_ERR);
	if (execve(path, cmd->args, rebuild_env(env)) == -1)
	{
		ft_log(I_ERROR, "An error occured while executing: ", path);
		exit(EXIT_FAILURE);
	}
	return (SH3_OK);
}

static char	*get_recommandation(t_env *env, char *name)
{
	char	*str;
	int		len;

	str = NULL;
	len = MIN(ft_strlen(name), 40);
	while (str == NULL && len > 0)
	{
		str = btree_search_item(env->bins_tree, name, ft_voidvoid);
		name[--len] = 0;
	}
	return (str);
}

int			exec_cmd(t_env *env, t_cmd *cmd)
{
	t_htab_elem	*elem;
	char		*str;

	prepare_command(cmd);
	if (do_builtin(env, cmd))
		return (SH3_OK);
	if (ft_strncmp(*(cmd->args), "./", 2) == 0)
		return (do_exec(env, *(cmd->args), cmd) == SH3_ERR);
	if (**(cmd->args) == '/')
		return (do_exec(env, *(cmd->args), cmd) == SH3_ERR);
	elem = ft_htab_get(env->bins, *(cmd->args));
	if (elem == NULL || elem->content == NULL)
	{
		ft_log(I_ERROR, "no such command: ", *(cmd->args));
		str = get_recommandation(env, cmd->args[0]);
		if (str != NULL)
			ft_log(I_HELP, "did you mean: ", str);
		else
			ft_log(I_WARNING, "no suggestion available", NULL);
		return (SH3_ERR);
	}
	if (do_exec(env, elem->content, cmd) == SH3_ERR)
		return (SH3_ERR);
	return (SH3_OK);
}

int			do_unpipe_cmd(t_env *env, t_cmd *cmd)
{
	int	state;

	if (do_builtin(env, cmd))
		return (SH3_OK);
	state = 0;
	if (ft_fork_cmd(env, cmd) == -1)
		return (SH3_ERR);
	if (env->data.process_id == 0)
	{
		if (exec_cmd(env, cmd) == SH3_ERR)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	wait(&state);
	handle_exited_state(cmd, state);
	return (SH3_OK);
}
