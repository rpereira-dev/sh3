/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:46:28 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/31 13:44:35 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		ft_putc(int c)
{
	static char	*buffer = NULL;
	static int	i = 0;
	char		*tmp;

	if (i % 1024 == 0)
	{
		if ((tmp = ft_memalloc(sizeof(char) * (i + 1024))) == NULL)
			fatal_error("Not enough memory", NULL);
		if (buffer != NULL)
		{
			ft_memcpy(tmp, buffer, 1024);
			free(buffer);
		}
		buffer = tmp;
	}
	if (c == C_FLUSH)
	{
		write(1, buffer, i);
		free(buffer);
		buffer = NULL;
		i = 0;
	}
	else
		buffer[i++] = c;
	return (1);
}

void	ft_tputs(char *cmd)
{
	char	*str;

	str = tgetstr(cmd, NULL);
	if (str != NULL)
	{
		tputs(str, 0, ft_putc);
		ft_putc(C_FLUSH);
	}
}
