/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/16 20:22:35 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"
#include <stdio.h>

int			stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	sortnums(int **arr, int size)
{
	int	tmp;
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j + 1 != size && (*arr)[j] > (*arr)[j + 1])
			{
				tmp = (*arr)[j];
				(*arr)[j] = (*arr)[j + 1];
				(*arr)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int *nums(t_stack *stack)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = stack_len(stack);	
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(-1);
	while (i < len)
	{
		arr[i] = stack->num;
		stack = stack->next;
		i++;
	}
	sortnums(&arr, len);
	return (arr);
}

void		indexation(t_stack **stack, int *arr)
{
	t_stack *a;
	int		i;

	a = (*stack);
	while (a)
	{
		i = 0;
		while (arr[i] != a->num)
			i++;
		a->index = i;
		a = a->next;
	}
	a = NULL;
	free(arr);
}

void		markup_head(t_stack **stack)
{
	int		index;
	t_stack	*a;

	a = (*stack);
	index = a->index;
	a->markup = 1;
	a = a->next;
	while (a)
	{
		if (a->index == index + 1)
		{
			index = a->index;
			a->markup = 1;
		}
		else
			a->markup = 0;
		a = a->next;
	}
}

int			check_false(t_stack *stack)
{
	t_stack *a;

	a = stack;
	while (a)
	{
		if (a->markup == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

int			howmanykeep(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->markup == 1)
			count++;
		stack = stack->next;
	}
	return (count);
}

static t_stack	*stacknew(t_stack *stack)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		exit(-1);
	new->num = stack->num;
	new->index = stack->index;
	new->markup = stack->markup;
	new->next = NULL;
	return (new);
}

t_stack		*stackcpy(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	new = stacknew(stack);
	if (stack)
		new->next = stackcpy(stack->next);
	return (new);
}

int			swap_need(t_stack **stack)
{
	t_stack	*a;
	t_stack	*cpy;
	int		keep;

	a = (*stack);
	keep = howmanykeep(a);
	cpy = stackcpy(a);
	sa(&cpy);
	markup_head(&cpy);
	if (howmanykeep(cpy) > keep)
	{
		delete_stack(&cpy);
		return (1);
	}
	delete_stack(&cpy);
	return (0);
}

void		wedding(t_stack **a, t_stack **b)
{
	int	tmp;
	int len;
	int	i;

	i = 0;
	len = stack_len((*a));
	while (*b)
	{
		if ((*b)->index < (*a)->index)
		{
			rra(a);
			tmp = (*a)->index;
			ra(a);
			if ((*b)->index > tmp)
			{
				pa(a, b);
				ft_putstr("pa\n");
				len = stack_len((*a));
			}
			else if (i == 0)
			{
				pa(a, b);
				ft_putstr("pa\n");
			}
			else
			{
				rra(a);
				ft_putstr("rra\n");
				i--;
			}
		}
		else if (i + 1 == len)
		{
			ra(a);
			pa(a, b);
			ft_putstr("ra\npa\n");
			len = stack_len((*a));
			i++;
		}
		else
		{
			ra(a);
			ft_putstr("ra\n");
			i++;
		}
		if (i == len)
			i = 0;
	}
	while ((*a)->index != 0)
	{
		ra(a);
		ft_putstr("ra\n");
	}
}

int			minind(t_stack *stack)
{
	int	ind;

	ind = stack->index;
	while (stack)
	{
		if (stack->index < ind)
			ind = stack->index;
		stack = stack->next;
	}
	return (ind);
}

void		fix(t_stack **stack)
{
	int		ind;
	
	ind = minind((*stack));
	while ((*stack)->index != ind)
	{
		rra(stack);
		ft_putstr("rra\n");	
	}
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		exit(-1);
	a = create_stack(argc, argv);
	b = NULL;
	indexation(&a, nums(a));
	markup_head(&a);
	while (check_false(a))
	{
		if (swap_need(&a))
		{
			sa(&a);
			markup_head(&a);
			ft_putstr("sa\n");
		}
		else if (a->markup == 0)
		{
			pb(&a, &b);
			ft_putstr("pb\n");
		}
		else
		{
			ra(&a);
			ft_putstr("ra\n");
		}
	}
	fix(&a);
	//print_stack(a, b);
	wedding(&a, &b);
	//print_stack(a, b);
	delete_stack(&a);
	delete_stack(&b);
	return (0);
}