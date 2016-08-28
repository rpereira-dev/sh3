/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3_logger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 12:20:43 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/01 14:32:41 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_print_log(int info, char *s1, char *s2, int size)
{
	char	buffer[size];

	ft_bzero(buffer, sizeof(buffer));
	(info == I_OK) ? ft_strcat(buffer, C_GREEN) : 0;
	(info == I_WARNING) ? ft_strcat(buffer, C_YELLOW) : 0;
	(info == I_ERROR) ? ft_strcat(buffer, C_RED) : 0;
	(info == I_HELP) ? ft_strcat(buffer, C_CYAN) : 0;
	ft_strcat(buffer, C_BOLD);
	ft_strcat(buffer, "sh3");
	ft_strcat(buffer, C_RESET);
	ft_strcat(buffer, " - ");
	ft_strcat(buffer, C_BOLD);
	(info == I_OK) ? ft_strcat(buffer, "info:\t") : 0;
	(info == I_WARNING) ? ft_strcat(buffer, "warning:\t") : 0;
	(info == I_ERROR) ? ft_strcat(buffer, "error:\t") : 0;
	(info == I_HELP) ? ft_strcat(buffer, "help:\t") : 0;
	ft_strcat(buffer, C_RESET);
	ft_strcat(buffer, s1);
	ft_strcat(buffer, s2);
	ft_putendl(buffer);
}

void		ft_log(int info, char *s1, char *s2)
{
	if (s1 == NULL)
		return ;
	ft_print_log(info, s1, s2, ft_strlen(s1) + ft_strlen(s2) + 255);
}

void		fatal_error(char *s1, char *s2)
{
	write(1, "\n", 1);
	ft_log(I_ERROR, s1, s2);
	exit(EXIT_FAILURE);
}
