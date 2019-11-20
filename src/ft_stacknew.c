/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:38:44 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/16 16:28:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*ft_newstackelem(char **arr);
static int		ft_checkrepeats(t_stack *stack);
static void		ft_arrdel(char **arr);
static void		ft_addtoend(t_stack **a, t_stack *b);

t_stack			*ft_stacknew(int argc, char **argv)
{
	t_stack	*stack;
	char	**arr;
	int		i;

	i = 2;
	arr = ft_strsplit(argv[1], ' ');
	stack = ft_newstackelem(arr);
	ft_arrdel(arr);
	while (i < argc)
	{
		arr = ft_strsplit(argv[i], ' ');
		ft_addtoend(&stack, ft_newstackelem(arr));
		ft_arrdel(arr);
		i++;
	}
	if (!ft_checkrepeats(stack))
		ft_stackdel(&stack);
	return (stack);
}

static void		ft_arrdel(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

static t_stack	*ft_newstackelem(char **arr)
{
	t_stack *new;
	int		i;

	i = 0;
	new = NULL;
	if (!(*arr))
		return (NULL);
	else if ((arr[i][0] == '-' ? !ft_isdigit(arr[i][1]) : !ft_isdigit(arr[i][0])))
	{
		ft_putstr("Error\n");
		exit(-1);
	}
	else if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	else
	{
		new->num = ft_atoi(arr[i]);
		new->index = 0;
		new->markup = 1;
		new->turns = 0;
		new->keep = 0;
		new->next = ft_newstackelem(arr + 1);
	}
	return (new);
}

static void		ft_addtoend(t_stack **a, t_stack *b)
{
	t_stack	*tmp;

	tmp = (*a);
	if (tmp && b)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = b;
	}
}

static int		ft_checkrepeats(t_stack *stack)
{
	t_stack	*start;
	t_stack	*tmp;
	int		num;
	int		count;

	start = stack;
	while (start)
	{
		count = 0;
		tmp = stack;
		num = start->num;
		while (tmp)
		{
			if (tmp->num == num)
				count++;
			tmp = tmp->next;
		}
		start = start->next;
		if (count != 1)
			return (0);
	}
	tmp = NULL;
	start = NULL;
	return (1);
}
