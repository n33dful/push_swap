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

static void		ft_check_stack_len(const t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		if (len > len + 1)
		{
			ft_putstr("Error\n");
			exit(-1);
		}
		stack = stack->next;
		len++;
	}
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
	if (!ft_isint((*arr)))
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
		new->markup = 0;
		new->turns = 0;
		new->keep = 0;
		new->str = NULL;
		new->next = ft_newstackelem(arr + 1);
	}
	return (new);
}

t_stack			*ft_stack_new(int argc, char **argv)
{
	t_stack	*stack;
	char	**arr;
	int		i;

	i = 2;
	arr = ft_strsplit(argv[1], ' ');
	stack = ft_newstackelem(arr);
	ft_delete_array(arr);
	while (i < argc)
	{
		arr = ft_strsplit(argv[i], ' ');
		ft_addtoend(&stack, ft_newstackelem(arr));
		ft_delete_array(arr);
		i++;
	}
	if (!ft_checkrepeats(stack))
		ft_stack_del(&stack);
	ft_check_stack_len(stack);
	return (stack);
}
