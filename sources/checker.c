/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:26:55 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:32:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	ft_stack_sorted(t_list *stack_a, t_list *stack_b)
{
	t_selem	*stack_elem;
	int		last_number;

	if (stack_b)
		return (0);
	last_number = ((t_selem *)stack_a->content)->number;
	while (stack_a)
	{
		stack_elem = stack_a->content;
		if (stack_elem->number >= last_number)
			last_number = stack_elem->number;
		else
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	ft_mirror_instructions(int flag_v, t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		gnl_status;

	line = NULL;
	while ((gnl_status = get_next_line(0, &line)) > 0)
	{
		if (!ft_stack_command(not_print_mode, line, stack_a, stack_b))
		{
			ft_strdel(&line);
			return (0);
		}
		if (flag_v)
			ft_stack_print(line, (*stack_a), (*stack_b));
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

static void	ft_parse_flags(int *flag_v, int *argc, char ***argv)
{
	if (ft_strequ((*argv)[1], "-v"))
	{
		*flag_v = 1;
		*argc -= 1;
		*argv +=1;
	}
}

static int	ft_program_completion(int code, t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstdel(stack_a, del_stack_elem);
	if (stack_b)
		ft_lstdel(stack_b, del_stack_elem);
	if (code == -1)
		ft_putendl_fd("Error", 2);
	return (code);
}

int			main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int		flag_v;

	flag_v = 0;
	if (argc == 1)
		return (0);
	ft_parse_flags(&flag_v, &argc, &argv);
	if (!(stack_a = ft_stack_new(argc, argv)))
		return (ft_program_completion(-1, &stack_a, NULL));
	stack_b = NULL;
	if (!ft_mirror_instructions(flag_v, &stack_a, &stack_b))
		return (ft_program_completion(-1, &stack_a, &stack_b));
	if (ft_stack_sorted(stack_a, stack_b))
		ft_putendl("\033[1;32mOK\033[0m");
	else
		ft_putendl("\033[1;31mKO\033[0m");
	return (ft_program_completion(0, &stack_a, &stack_b));
}
