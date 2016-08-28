/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:26:05 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 20:47:03 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

#define PWD_MAX_LENGTH 1024

int			calc_prompt_len(void)
{
	char	path[PWD_MAX_LENGTH + 1];
	int		len;
	char	*dir;

	ft_bzero(path, sizeof(path));
	getcwd(path, PWD_MAX_LENGTH * sizeof(char));
	len = 2;
	dir = ft_strrchr(path, '/');
	len += (dir != NULL ? ft_strlen(dir + 1) : ft_strlen("(null)"));
	if (!access(".git", F_OK))
	{
		len += ft_strlen(" (git) ");
	}
	else
	{
		len += 2;
	}
	return (len);
}

static void	print_prompt(t_env *env)
{
	char	path[PWD_MAX_LENGTH + 1];
	char	*dir;

	ft_bzero(path, sizeof(path));
	getcwd(path, PWD_MAX_LENGTH * sizeof(char));
	ft_putstr((env->state & SH3_ERR) ? C_BRED : C_BGREEN);
	ft_putwc(WC_AIRPLANE);
	ft_putstr("  ");
	ft_putstr(C_BBLUE);
	dir = ft_strrchr(path, '/');
	ft_putstr(dir != NULL ? dir + 1 : "(null)");
	ft_putstr(C_RESET);
	if (!access(".git", F_OK))
	{
		ft_putstr(C_BCYAN);
		ft_putstr(" (git) ");
		ft_putstr(C_RESET);
	}
	else
	{
		ft_putstr("  ");
	}
}

int			prompt(t_env *env, char **line)
{
	int	prompt_len;
	int	r;

	signal(SIGINT, SIG_IGN);
	prompt_len = calc_prompt_len();
	print_prompt(env);
	env->state = SH3_OK;
	r = sh3_get_next_line(line, prompt_len) > 0;
	write(1, "\n", 1);
	return (r);
}
