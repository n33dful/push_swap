/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:38:44 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/16 16:28:06 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void		delarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_stack	*stacknew(char **arr)
{
	t_stack *new;
	int		i;

	i = 0;
	new = NULL;
	if (!(*arr))
		return (NULL);
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = ft_atoi(arr[i]);
	new->index = 0;
	new->markup = 1;
	new->next = stacknew(arr + 1);
	return (new);
}

static void		add(t_stack **a, t_stack *b)
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
	char	**arr;
	int		i;

	i = 2;
	arr = ft_strsplit(argv[1], ' ');
	stack = stacknew(arr);
	delarr(arr);
	while (i < argc)
	{
		arr = ft_strsplit(argv[i], ' ');
		add(&stack, stacknew(arr));
		delarr(arr);
		i++;
	}
	return (stack);
}
