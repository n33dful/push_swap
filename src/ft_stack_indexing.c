/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:17:16 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 20:17:39 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_sort_numbers(int **array_of_numbers, int size)
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
			if (j + 1 != size && \
(*array_of_numbers)[j] > (*array_of_numbers)[j + 1])
			{
				tmp = (*array_of_numbers)[j];
				(*array_of_numbers)[j] = (*array_of_numbers)[j + 1];
				(*array_of_numbers)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*ft_create_an_array_of_numbers(t_stack *stack)
{
	int	*array_of_numbers;
	int	len;
	int	i;

	i = 0;
	len = ft_stack_len(stack);
	if (!(array_of_numbers = (int *)malloc(sizeof(int) * len)))
		exit(-1);
	while (i < len)
	{
		array_of_numbers[i] = stack->num;
		stack = stack->next;
		i++;
	}
	ft_sort_numbers(&array_of_numbers, len);
	return (array_of_numbers);
}

void		ft_stack_indexind(t_stack **stack)
{
	t_stack *stack_pointer;
	int		*array_of_numbers;
	size_t	i;

	array_of_numbers = ft_create_an_array_of_numbers((*stack));
	stack_pointer = (*stack);
	while (stack_pointer)
	{
		i = 0;
		while (array_of_numbers[i] != stack_pointer->num)
			i++;
		stack_pointer->index = i;
		stack_pointer = stack_pointer->next;
	}
	stack_pointer = NULL;
	free(array_of_numbers);
}
