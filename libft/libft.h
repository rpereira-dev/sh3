/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpereira <rpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:21:23 by rpereira          #+#    #+#             */
/*   Updated: 2015/04/01 17:01:20 by rpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ABS(x) ((x) > 0 ? (x) : -(x))
# define MAX(x, y) ((x) > (y) ? (x) : (y))
# define MIN(x, y) ((x) < (y) ? (x) : (y))
# define SIGN(x) ((x) < 0 ? (-1) : (1))

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wchar.h>
# include "color.h"
# include "e_wchar.h"

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_htab_elem
{
	void			*content;
	char			*key;
	size_t			index;
}					t_htab_elem;

typedef struct		s_htab
{
	t_list			**elems;
	size_t			size;
}					t_htab;

size_t				ft_htab_hash(char *str, size_t size);
void				ft_htab_insert(t_htab *tab, char *key, void *d, size_t s);
t_htab				*ft_htab_new(size_t size);
t_htab_elem			*ft_htab_get(t_htab *tab, char *key);
void				ft_htab_free(t_htab *tab);
void				ft_htab_iter(t_htab *tab, void *extra,
					void (*f)(void *, t_htab_elem *));

int					get_next_line(int const fd, char **line);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *neww);
void				ft_lstpush(t_list **alst, t_list *neww);
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstsize(t_list *begin);
void				ft_lstfree(t_list **lst, void (*ft_free)());

t_btree				*btree_create_node(void *item);
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root, void *item,
					int (*cmpf)(void*, void*));
void				*btree_search_item(t_btree *root, void *data_ref,
					int (*cmpf)(void*, void*));
int					btree_level_count(t_btree *root);

size_t				ft_strlen(const char *s);
int					ft_nbrlen(int n);
size_t				ft_wcrtomb(char *s, wchar_t wc);
size_t				ft_wstrlen(const wchar_t *s);
void				ft_putchar(char c);
void				ft_putchar_(char c, int canal);
void				ft_putnbr(int i);
void				ft_putnbr_(int i, int canal);
void				ft_putstr(const char *s);
void				ft_putstr_(const char *s, int canal);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putwc(wchar_t wc);
int					ft_putws(wchar_t *ws);
int					ft_atoi(const char *s);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_is_whitespace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_swap(int *a, int *b);

int					ft_strsplit_size(char **tab);
int					ft_strsplit_contains(char **tab, char *sequence);
void				free_strsplit(char **tab);
char				**ft_strsplit(char const *s, char c);
void				ft_swip_strsplit(char **tab, int from, int amount);

char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *src, int length);
char				*ft_strndup(const char *src, int n);
char				*ft_strcpy(char *dst, const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strncat(char *dest, const char *src, size_t size);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_void_cmp(void *a, void *b);
int					ft_voidvoid(void *a, void *b);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_itoa(int n);
void				ft_strdel(char **as);
int					ft_tab_contains(char **tab, char *sequence);
int					ft_indexof(char *str, char c);
int					ft_last_indexof(char *str, char c);

char				*ft_strrev(char *str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
int					ft_ccount(char *str, char c);

int					ft_match(char *s1, char *s2);

#endif
