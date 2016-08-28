/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:26:42 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/28 12:18:57 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int		is_redirect(char *str)
{
	if (!ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (2);
	if (!ft_strcmp(str, "<"))
		return (1);
	if (!ft_strcmp(str, "<<"))
		return (2);
	if (!ft_strcmp(str, "|"))
		return (1);
	return (0);
}

static int		count_cmd_words(char **cmd_t)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd_t[i])
	{
		if (i == 0 || (!is_redirect(cmd_t[i]) && !is_redirect(cmd_t[i - 1])))
			count++;
		else if (is_redirect(cmd_t[i]) && cmd_t[i + 1] == NULL)
		{
			ft_log(I_ERROR, "redirection error near: ", cmd_t[i]);
			get_env()->state = SH3_ERR;
		}
		i++;
	}
	return (count);
}

static t_cmd	isolate_command(char **cmd_t, int id)
{
	t_cmd	cmd;
	int		i;
	int		j;
	int		c;

	cmd.args = NULL;
	cmd.id = id;
	if ((c = count_cmd_words(cmd_t)) == -1)
		return (cmd);
	if ((cmd.args = (char**)malloc(sizeof(char*) * (c + 1))) == NULL)
		return (cmd);
	i = 0;
	j = 0;
	while (cmd_t[i] != NULL)
	{
		if (i == 0 || (!is_redirect(cmd_t[i - 1]) && (!is_redirect(cmd_t[i]))))
			cmd.args[j++] = ft_strdup(cmd_t[i]);
		i++;
	}
	cmd.args[j] = NULL;
	return (cmd);
}

t_list			*ft_parse_cmd(char *line)
{
	t_list	*elems;
	t_cmd	cmd;
	char	**pipes;
	char	**cmd_t;
	int		i;

	i = 0;
	elems = NULL;
	pipes = ft_strsplit(line, '|');
	while (pipes[i] != NULL)
	{
		cmd_t = ft_strsplit_whitespaces(pipes[i]);
		cmd = isolate_command(cmd_t, i);
		register_cmd_fd(cmd_t, &cmd);
		if (cmd.args != NULL)
			ft_lstpush(&elems, ft_lstnew(&cmd, sizeof(t_cmd)));
		free_strsplit(cmd_t);
		i++;
	}
	free_strsplit(pipes);
	return (elems);
}

t_list			*ft_parse_input(char *line)
{
	t_list	*cmds_lst;
	t_list	*elem;
	char	**cmds;
	char	*trim;
	int		i;

	trim = ft_strtrim(line);
	cmds = ft_strsplit(trim, ';');
	free(trim);
	i = 0;
	cmds_lst = NULL;
	while (cmds[i] != NULL)
	{
		trim = ft_strtrim(cmds[i]);
		if ((elem = ft_parse_cmd(trim)) != NULL)
		{
			ft_lstpush(&cmds_lst, ft_lstnew(elem, sizeof(t_list)));
			free(elem);
		}
		free(trim);
		free(cmds[i]);
		i++;
	}
	free(cmds);
	return (cmds_lst);
}
