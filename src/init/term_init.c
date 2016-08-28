/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:11:49 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 20:04:14 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	raw_terminal_mode(void)
{
	static struct termios	term;
	static int				initialized = 0;

	if (initialized == 0)
	{
		if (tgetent(NULL, getenv("TERM")) != 1)
			fatal_error("Invalid terminal informations", NULL);
		if (tcgetattr(STDIN_FILENO, &term) != 0)
		{
			if (errno == EBADF)
				fatal_error("fd is not a valid file descriptor", NULL);
			else if (errno == ENOTTY)
				fatal_error("File descriptor is not a terminal", NULL);
			else
				fatal_error("Unknow error", NULL);
		}
		term.c_lflag = term.c_lflag & ~(ICANON | ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		initialized = 1;
	}
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) == -1)
		fatal_error("couldnt set terminal attributes", NULL);
}

void	default_terminal_mode(void)
{
	static struct termios	term;
	static int				initialized = 0;

	if (initialized == 0)
	{
		if (tgetent(NULL, getenv("TERM")) != 1)
			fatal_error("Invalid terminal informations", NULL);
		if (tcgetattr(STDIN_FILENO, &term) != 0)
		{
			if (errno == EBADF)
				fatal_error("Not a valid file descriptor", NULL);
			else if (errno == ENOTTY)
				fatal_error("fd is not a terminal", NULL);
			else
				fatal_error("Unknow error", NULL);
		}
		term.c_lflag = term.c_lflag | ICANON | ECHO;
		initialized = 1;
	}
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) == -1)
		fatal_error("couldnt set terminal attributes", NULL);
}
