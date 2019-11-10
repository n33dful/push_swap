/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:38:44 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/10 19:12:08 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static t_stack	*stacknew(char *num)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = ft_atoi(num);
	new->next = NULL;
	return (new);
}

static void		stack_add(t_stack **a, t_stack *b)
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

t_stack			*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = stacknew(argv[i]);
	i++;
	while (i < argc)
	{
		stack_add(&stack, stacknew(argv[i]));
		i++;
	}
	return (stack);
}