/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 09:13:35 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/03 11:21:25 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	join_matched_word(t_dirent *entry, int match_len)
{
	while (match_len--)
		handle_k_backspace();
	handle_none(entry->d_name, strlen(entry->d_name));
	if (entry->d_type & DT_DIR)
		handle_none("/", 1);
}

static void	parcour_dir(char *str, int len, char *dir_name)
{
	DIR				*dir;
	t_dirent		*entry;
	char			buffer[len + 3];

	buffer[0] = '*';
	ft_strncpy(buffer + 1, str, len);
	buffer[len + 1] = '*';
	buffer[len + 2] = 0;
	if ((dir = opendir(dir_name)) == NULL)
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		if (!ft_strcmp(entry->d_name, ".") || !ft_strcmp(entry->d_name, ".."))
			continue ;
		if (entry->d_name[0] == '.' && str[0] != '.')
			continue ;
		if (ft_match(entry->d_name, buffer))
		{
			join_matched_word(entry, len);
			break ;
		}
	}
	closedir(dir);
}

static char	*get_str_to_match(char *str)
{
	int		index;

	if (str == NULL)
		return (NULL);
	index = g_line->index;
	while (index > 0 && str[index] != ' ' &&
			str[index] != '\t' && str[index] != '/')
	{
		index--;
	}
	if (index == 0)
	{
		return (ft_strdup(str));
	}
	return (ft_strndup(str + index + 1, g_line->index - index));
}

static char	*get_parcour_dir(char *str)
{
	char	*ptr;
	int		index;

	if (str == NULL)
		return (NULL);
	index = g_line->index;
	while (index > 0 && str[index] != ' ' && str[index] != '\t')
	{
		index--;
	}
	if ((ptr = ft_strrchr(str + index, '/')) == NULL)
		return (ft_strdup("."));
	return (ft_strndup(str + index + 1, ptr - (str + index)));
}

int			handle_k_tab(void)
{
	char	*str;
	char	*match;
	int		match_len;
	char	*dir;

	str = ft_chars_to_str(g_line->chars, g_line->c_chars);
	match = get_str_to_match(str);
	match_len = ft_strlen(match);
	dir = get_parcour_dir(str);
	parcour_dir(match, match_len, dir);
	free(match);
	free(str);
	free(dir);
	return (K_TAB);
}
