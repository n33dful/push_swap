/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:26:55 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/21 21:28:48 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static char	*program_output(void)
{
	char	*line;
	char	*tmp;
	char	buf[21];
	int		rd;

	line = ft_strnew(0);
	while ((rd = read(0, buf, 21)) > 0)
	{
		buf[rd] = '\0';
		tmp = ft_strjoin(line, buf);
		ft_strdel(&line);
		line = tmp;
	}
	return (line);
}

static int	ft_is_the_stack_sorted(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	tmp = a;
	if (b != NULL)
		return (0);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_error_messgage(char **commands)
{
	ft_strdel(commands);
	ft_putstr("Error\n");
	exit(-1);
}

static void	ft_mirror_instructions(t_stack **a, t_stack **b, \
int argc, char **argv)
{
	char	*commands;

	commands = program_output();
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		if (!((*a) = ft_stack_new(argc - 1, &argv[1])))
			ft_error_messgage(&commands);
		ft_checker_stack_print(commands, a, b, 1);
	}
	else
	{
		if (!((*a) = ft_stack_new(argc, &argv[0])))
			ft_error_messgage(&commands);
		ft_checker_stack_print(commands, a, b, 0);
	}
	ft_strdel(&commands);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	ft_mirror_instructions(&a, &b, argc, argv);
	if (ft_is_the_stack_sorted(a, b))
		ft_putstr("\033[1;32mOK\n\033[0m");
	else
		ft_putstr("\033[1;31mKO\n\033[0m");
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
