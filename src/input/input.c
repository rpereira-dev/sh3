/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:04:37 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 19:44:16 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	sh3_input(char buffer[MAX_KEY_LEN])
{
	int	i;

	if (g_line == NULL)
		return (K_ENTER);
	i = 0;
	while (i < MAX_KEY)
	{
		if (ft_strcmp(buffer, g_key_handler[i].key) == 0)
			return (g_key_handler[i].handler(buffer));
		i++;
	}
	return (g_key_handler[K_NONE].handler(buffer, MAX_KEY_LEN));
}

static void	catch_sigint(int sig)
{
	if (sig == SIGINT)
	{
		if (g_current_node == NULL)
		{
			ft_chars_free(&(g_line->chars));
			free(g_line);
		}
		g_line = NULL;
		//ioctl(0, TIOCSTI, "\n");
	}
}

static void	init_line(int prompt_len)
{
	if ((g_line = (t_line*)ft_memalloc(sizeof(t_line))) == NULL)
	{
		ft_log(I_ERROR, "Not enough memory", NULL);
		exit(EXIT_FAILURE);
	}
	g_line->prompt_len = prompt_len;
	raw_terminal_mode();
	g_current_node = NULL;
	ft_parenthese_iter(init_parenthese);
	signal(SIGINT, catch_sigint);
}

static char	*line_to_str(void)
{
	if (g_line == NULL || g_line->chars == NULL)
		return (NULL);
	return (ft_chars_to_str(g_line->chars, g_line->c_chars));
}

int			sh3_get_next_line(char **str, int prompt_len)
{
	char	buffer[MAX_KEY_LEN];
	int		input;

	init_line(prompt_len);
	ft_bzero(buffer, sizeof(buffer));
	while (read(0, buffer, MAX_KEY_LEN) > 0)
	{
		input = sh3_input(buffer);
		if (input == K_ENTER)
		{
			*str = line_to_str();
			default_terminal_mode();
			return (1);
		}
		ft_bzero(buffer, sizeof(buffer));
	}
	return (0);
}
