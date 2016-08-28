/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_cmd_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 08:23:55 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 10:48:04 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static char	*get_path(char *parent, char *child, int psize, int csize)
{
	char	*path;

	path = (char*)ft_memalloc(sizeof(char) * (psize + csize + 2));
	ft_strcpy(path, parent);
	ft_strcat(path, "/");
	ft_strcat(path, child);
	return (path);
}

static void get_exec_file(t_htab *bins, char *path, char *name, int namlen)
{
	char			*full_path;
	struct stat		s;

	full_path = get_path(path, name, namlen, ft_strlen(path));
	if (full_path != NULL)
	{
		if (stat(full_path, &s) == -1)
		{
			ft_log(I_WARNING, "couldnt get file stats: ", full_path);
		}
		else if (S_ISREG(s.st_mode) && s.st_mode & S_IXUSR)
		{
			ft_htab_insert(bins, name, full_path, ft_strlen(full_path) + 1);
		}
		free(full_path);
	}
}

static void	get_execs(t_htab *bins, char *path)
{
	DIR			*dir;
	t_dirent	*entry;

	if ((dir = opendir(path)) == NULL)
	{
		ft_log(I_WARNING, "couldn't open: ", path);
		return ;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		get_exec_file(bins, path, entry->d_name, sizeof(entry->d_name) + 1);
	}
	closedir(dir);
}

void		fill_htab(t_env *env)
{
	t_var	*var;
	char	**path;
	int		i;

	var = get_env_var(env, "PATH", 1);
	if (var == NULL || var->content == NULL)
		return ;
	i = 0;
	path = ft_strsplit(var->content, ':');
	while (path[i] != NULL)
	{
		get_execs(env->bins, path[i]);
		free(path[i]);
		i = i + 1;
	}
	free(path);
}
