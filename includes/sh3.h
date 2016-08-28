/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 11:24:52 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 18:51:29 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH3_H
# define SH3_H
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <stdint.h>
# include <dirent.h>
# include <signal.h>

# include "libft.h"
# include "input.h"
# include "chars.h"

# include <errno.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

# define FD_STDIN 0
# define FD_STDOUT 1
# define PIPE_IN 1
# define PIPE_OUT 0

typedef struct	s_builtin
{
	char	*name;
	void	(*do_builtin)();
}				t_builtin;

enum			e_redirection_type
{
	REDIR_NONE,
	REDIR_OUT_TRUNC,
	REDIR_OUT_APPEND,
	REDIR_IN_FILE
};

typedef struct	s_cmd
{
	char	**args;
	char	*file_in;
	char	*file_out;
	int		redirection;
	int		id;
	int		pid;
}				t_cmd;

typedef struct	s_var
{
	char		*name;
	char		*content;
}				t_var;

enum			e_access_bits
{
	E_EXIST = 1,
	E_EXEC = 2,
	E_READ = 4,
	E_WRITE = 8
};

enum			e_sh3_state
{
	SH3_OK = 0,
	SH3_ERR = 1
};

typedef struct	s_env_data
{
	t_list	*cmd;
	pid_t	process_id;
	int		stdin_fd;
	int		stdout_fd;
}				t_env_data;

typedef struct	s_env
{
	t_list		*environ;
	t_btree		*bins_tree;
	t_htab		*bins;
	t_env_data	data;
	int			state;
}				t_env;

enum			e_info
{
	I_OK = 1,
	I_WARNING = 2,
	I_ERROR = 3,
	I_HELP = 4
};

extern t_builtin	g_builtin[];

/*
**	Parsing functions
*/
char			*first_line_parse(char *line);
t_list			*ft_parse_input(char *line);
char			**ft_strsplit_whitespaces(char const *s);
t_cmd			new_cmd(void);

/*
**	Input
*/
int				sh3_get_next_line(char **line, int prompt_len);
void			ft_tputs(char *cmd);

/*
**	Env functions
*/
t_env			*get_env(void);
t_var			*get_env_var(t_env *env, char *name, int err);
void			set_env_var(t_env *env, char *name, char *value);
void			add_env_var(t_env *env, char *name, char *content);
void			remove_env_var(t_env *env, char *name, int err);
void			init_env(t_env *env, char **environ);
void			init_config(t_env *env);
void			free_env(t_env *env);
void			save_env_var(t_env *env, char **environ);
char			**rebuild_env(t_env *env);

/*
**	Termcap thingies
*/
void			raw_terminal_mode(void);
void			default_terminal_mode(void);
int				ft_putc(int c);

/*
**	Loop
*/
void			shell_loop(t_env *env);
int				prompt(t_env *env, char **str);
pid_t			ft_fork_cmd(t_env *env, t_cmd *cmd);

/*
**	Redireciton functions
*/
int				open_file(char *file, int append);
void			save_std_fd(void);
void			register_cmd_fd(char **args, t_cmd *cmd);
void			register_cmd_pipe(char **args, t_list *cmd);
void			init_pipeline(int fds[][2], int pipes);
void			close_pipeline(int fds[][2], int pipes);
void			prepare_command(t_cmd *cmd);
void			close_pipe(int fds[2]);
void			handle_pipe(int fds[2], int to_close, int to_dup, int dup_dir);

/*
**	Exec functions
*/
int				do_builtin(t_env *env, t_cmd *cmd);
int				exec_cmd(t_env *env, t_cmd *cmd);
int				do_unpipe_cmd(t_env *env, t_cmd *cmd);
int				exec_pipeline(t_env *env, t_list *cmds, int pipes);
void			fill_htab(t_env *env);
void			free_cmd(t_cmd *cmd);

/*
**	Logger / Error handlers
*/
void			catch_process_interupt(int signo);
int				file_is_accessible(t_env *env, char *file, int indices);
void			ft_log(int info, char *s1, char *s2);
void			fatal_error(char *s1, char *s2);
void			handle_exited_state(t_cmd *cmd, int state);

/*
**	Builtins
*/
void			do_cd(t_env *env, char **args);
void			do_exit(void);
void			do_env(t_env *env);
void			do_setenv(t_env *env, char **args);
void			do_unsetenv(t_env *env, char **args);
void			do_cpenv(t_env *env, char **args);
void			ft_cat(char *file, int dst_fd);

#endif
