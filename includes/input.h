/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:29:44 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/02 16:19:24 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define MAX_PARENTHESE 6
# define MAX_KEY 27
# define MAX_KEY_LEN 16

# define C_FLUSH '\n'
# define PARENTHESE_PROMPT "> "
# define PARENTHESE_PROMPT_LEN 2
# define PROMPT_LEN (calc_prompt_len())

# include "chars.h"

typedef struct	s_key_handler
{
	char	key[MAX_KEY_LEN];
	int		(*handler)();
}				t_key_handler;

typedef struct dirent	t_dirent;

enum			e_parenthese_state
{
	PARENTHESE_CLOSE,
	PARENTHESE_OPEN
};

enum			e_key
{
	K_NONE,
	K_LEFT,
	K_UP,
	K_RIGHT,
	K_DOWN,
	K_BACKSPACE,
	K_DELETE,
	K_ENTER,
	K_CTRL_D,
	K_CTRL_U,
	K_TAB,
	K_END,
	K_HOME,
	K_SHIFT_END,
	K_SHIFT_HOME,
	K_SHIFT_LEFT,
	K_SHIFT_RIGHT,
	K_SHIFT_DOWN,
	K_SHIFT_UP,
	K_CTRL_K,
	K_CTRL_P,
	K_CTRL_L,
	K_CTRL_H,
	K_OPTIONS_LEFT,
	K_OPTIONS_RIGHT,
	K_OPTIONS_UP,
	K_OPTIONS_DOWN
};

typedef struct	s_line
{
	t_char		*chars;
	int			c_chars;
	int			index;
	int			x_cur;
	int			prompt_len;
	uint8_t		state;
}				t_line;

enum			e_line_state
{
	LINE_SAVED = 1,
	LINE_CANCELED = 2,
	LINE_SELECTING = 4
};

typedef struct	s_parenthese
{
	char	c_open;
	char	c_close;
	char	name[8];
	int		state;
}				t_parenthese;

extern t_parenthese		g_parenthese[MAX_PARENTHESE];
extern t_key_handler	g_key_handler[MAX_KEY];
extern t_line			*g_line;
extern t_list			*g_history_lst;
extern t_list			*g_current_node;

int				calc_prompt_len(void);

/*
**	Parentheses
*/
void			ft_parenthese_iter(void (*f)(t_parenthese *));
void			init_parenthese(t_parenthese *p);
int				check_parentheses(void);
void			check_parentheses_state(char c);
int				check_parenthese_char(char c);
void			print_parenthese(t_parenthese *p);

/*
**	Key handlers
*/
int				handle_none(char *str, int len);
int				handle_k_left(void);
int				handle_k_right(void);
int				handle_k_up(void);
int				handle_k_down(void);
int				handle_k_backspace(void);
int				handle_k_delete(void);
int				handle_k_enter(void);
int				handle_k_ctrl_d(void);
int				handle_k_ctrl_u(void);
int				handle_k_tab(void);
int				handle_k_end(void);
int				handle_k_home(void);
int				handle_k_shift_left(void);
int				handle_k_shift_right(void);
int				handle_k_shift_down(void);
int				handle_k_shift_up(void);
int				handle_k_ctrl_k(void);
int				handle_k_ctrl_p(void);
int				handle_k_ctrl_l(void);
int				handle_k_ctrl_h(void);
int				handle_k_nothing(void);

void			ft_place_cursor(int x, int y);

/*
**	History
*/
t_line			*dup_line(void);
int				ft_compare_line(void *d1, void *d2);
void			save_line(void);

#endif
