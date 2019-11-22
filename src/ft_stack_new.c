/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:38:44 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 21:15:43 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		ft_check_numbers_in_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr || !arr[i])
	{
		ft_delete_array(arr);
		return (0);
	}
	while (arr[i])
	{
		if (!ft_isint(arr[i++]))
		{
			ft_delete_array(arr);
			return (0);
		}
	}
	return (1);
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

static t_stack	*ft_newstackelem(char **arr)
{
	t_stack *new;
	int		i;

	i = 0;
	new = NULL;
	if (!(*arr))
		return (NULL);
	else if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	else
	{
		new->num = ft_atoi(arr[i]);
		new->index = 0;
		new->markup = 0;
		new->turns = 0;
		new->str = NULL;
		new->next = ft_newstackelem(arr + 1);
	}
	ft_delete_array(arr);
	return (new);
}

t_stack			*ft_stack_new(int ac, char **av)
{
	t_stack	*stack;
	char	**arr;
	int		i;

	i = 1;
	if (!(arr = ft_strsplit(av[i++], ' ')) || !ft_check_numbers_in_arr(arr))
		return (NULL);
	stack = ft_newstackelem(arr);
	while (i < ac)
	{
		if (!(arr = ft_strsplit(av[i++], ' ')) || !ft_check_numbers_in_arr(arr))
		{
			ft_stack_del(&stack);
			return (NULL);
		}
		ft_addtoend(&stack, ft_newstackelem(arr));
	}
	if (!ft_checkrepeats(stack))
		ft_stack_del(&stack);
	return (stack);
}
