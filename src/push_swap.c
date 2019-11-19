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

#include "../include/push_swap.h"
#include <stdio.h>

static void	ft_indexation(t_stack **stack, int *arr);
static void	ft_sortnums(int **arr, int size);
static void	ft_showerror();
static int	*ft_arrofnums(t_stack *stack);

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2 || !(a = ft_stacknew(argc, argv)))
		ft_showerror();
	b = NULL;
	ft_indexation(&a, ft_arrofnums(a));
	ft_divorce(&a, &b);
	ft_wedding(&a, &b);
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (0);
}

static void	ft_showerror()
{
	ft_putstr("Error\n");
	exit(-1);
}

static void	ft_sortnums(int **arr, int size)
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

static int	*ft_arrofnums(t_stack *stack)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = ft_stacklen(stack);	
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(-1);
	while (i < len)
	{
		arr[i] = stack->num;
		stack = stack->next;
		i++;
	}
	ft_sortnums(&arr, len);
	return (arr);
}

static void	ft_indexation(t_stack **stack, int *arr)
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
