/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:27:59 by rpereira          #+#    #+#             */
/*   Updated: 2015/03/23 17:49:58 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		main(int argc, char **argv, char **environ)
{
	t_env	*env;

	(void)argc;
	(void)argv;
	env = get_env();
	init_env(env, environ);
	init_config(env);
	shell_loop(env);
	free_env(env);
	return (0);
}
