/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_stack_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:36:59 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 23:22:31 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	ft_error_message(char *commands, char **comm, \
t_stack **a, t_stack **b)
{
	ft_putendl("Error");
	ft_strdel(&commands);
	ft_delete_array(comm);
	ft_stack_del(a);
	ft_stack_del(b);
	exit(-1);
}

static int	ft_what_to_do(char *comm, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(comm, "sa") || !ft_strcmp(comm, "sb") || \
!ft_strcmp(comm, "ss") || !ft_strcmp(comm, "pa") || !ft_strcmp(comm, "pb") || \
!ft_strcmp(comm, "ra") || !ft_strcmp(comm, "rb") || !ft_strcmp(comm, "rr") || \
!ft_strcmp(comm, "rra") || !ft_strcmp(comm, "rrb") || !ft_strcmp(comm, "rrr"))
	{
		if (!ft_strcmp(comm, "sa") || !ft_strcmp(comm, "ss"))
			ft_stack_swap(a);
		if (!ft_strcmp(comm, "sb") || !ft_strcmp(comm, "ss"))
			ft_stack_swap(b);
		if (!ft_strcmp(comm, "pa"))
			ft_stack_push(b, a);
		if (!ft_strcmp(comm, "pb"))
			ft_stack_push(a, b);
		if (!ft_strcmp(comm, "ra") || !ft_strcmp(comm, "rr"))
			ft_stack_rotate(a);
		if (!ft_strcmp(comm, "rb") || !ft_strcmp(comm, "rr"))
			ft_stack_rotate(b);
		if (!ft_strcmp(comm, "rra") || !ft_strcmp(comm, "rrr"))
			ft_stack_reverse_rotate(a);
		if (!ft_strcmp(comm, "rrb") || !ft_strcmp(comm, "rrr"))
			ft_stack_reverse_rotate(b);
		return (1);
	}
	return (0);
}

void		ft_checker_stack_print(char *commands, \
t_stack **a, t_stack **b, int v)
{
	char	**comm;
	int		i;

	i = 0;
	comm = ft_strsplit(commands, '\n');
	if (v)
		ft_stack_print((*a), (*b));
	while (comm[i])
	{
		if (!(ft_what_to_do(comm[i], a, b)))
			ft_error_message(commands, comm, a, b);
		if (v)
		{
			ft_putstr("\033[1;33m>----------{ ");
			ft_putstr(comm[i]);
			if (ft_strlen(comm[i]) == 2)
				ft_putendl("  }----------<\033[0m");
			else
				ft_putendl(" }----------<\033[0m");
			ft_stack_print((*a), (*b));
		}
		i++;
	}
	ft_delete_array(comm);
}
