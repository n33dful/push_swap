/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:59:54 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 21:26:18 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** ***************************** External Includes *****************************
*/

# include "get_next_line.h"
# include "t_list.h"
# include "t_tree.h"

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*
** ********** Functions For Working With Character Arrays Defenitions **********
*/

void	**ft_arrnew(size_t count);
void	ft_arrdel(void ***array);

/*
** ************ Functions For Working With Bibary Trees Defenitions ************
*/

t_list	*ft_treetolist(t_tree *tree);
t_tree	*ft_treenew(void *content);
void	ft_treeadd(t_tree **tree, t_tree *node, char (*f)(void *, void *));
void	ft_treeclear(t_tree **node, void (*del)(void *));
void	ft_treedelone(t_tree *node, void (*del)(void *));
void	ft_treeiter(t_tree *tree, void (*f)(void *));

/*
** ************** Function For Working With Integers Defenitions ***************
*/

char	*ft_itoa(int n);

/*
** ************** Functions For Working With Printing Defenitions **************
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putendl_colored(char const *s, char const *color);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putstr_colored(char const *s, char const *color);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);

/*
** ************** Functions For Working With Strings Defenitions ***************
*/

char	**ft_strsplit(char const *s, char c);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strchr(char const *s, int c);
char	*ft_strcpy(char *dst, char const *src);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, char const *s2, size_t n);
char	*ft_strncpy(char *dst, char const *src, size_t n);
char	*ft_strnew(size_t n);
char	*ft_strnstr(char const *haystack, char const *needle, size_t n);
char	*ft_strrchr(char const *s, int c);
char	*ft_strstr(char const *haystack, char const *needle);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
size_t	ft_strlcat(char *dst, char const *src, size_t len);
size_t	ft_strlen(char const *s);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
** *************** Functions For Checking Character Defenitions ****************
*/

int		ft_isalnum(char c);
int		ft_isalpha(char c);
int		ft_isascii(char c);
int		ft_isblank(char c);
int		ft_iscntrl(char c);
int		ft_isdigit(char c);
int		ft_isinteger(char const *str);
int		ft_islower(char c);
int		ft_isprint(char c);
int		ft_isspace(char c);
int		ft_isupper(char c);

/*
** *************** Functions For Working With Lists Defenitions ****************
*/

size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstsorted(t_list *lst, char (*f)(void *, void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstloop_break(t_list *lst);
void	ft_lstloop_create(t_list *lst);
void	ft_lstsort(t_list **lst, char (*f)(void *, void *));

/*
** *************** Functions For Working With Memory Defenitions ***************
*/

int		ft_memcmp(void const *s1, void const *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memalloc(size_t n);
void	*ft_memccpy(void *dst, void const *src, int c, size_t n);
void	*ft_memchr(void const *s, int c, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t n);
void	*ft_memset(void *ptr, int c, size_t len);
void	ft_bzero(void *ptr, size_t n);
void	ft_memdel(void **ap);

/*
** **************** Functions For Convert Character Defenitions ****************
*/

char	ft_tolower(char c);
char	ft_toupper(char c);

/*
** *****************************************************************************
*/

#endif
