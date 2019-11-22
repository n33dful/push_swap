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
	ft_putendl("Error");
	exit(-1);
}

static int	ft_mirror_instructions(t_stack **a, t_stack **b, \
int ac, char **av)
{
	char	*commands;
	int		flag_v;

	flag_v = 0;
	commands = program_output();
	if (ft_strcmp(av[1], "-v") == 0)
	{
		if (ac < 3)
			return (0);
		av = av + 1;
		flag_v = 1;
	}
	else if (ac < 2)
		return(0);
	if (!((*a) = ft_stack_new(ac, av)))
		ft_error_messgage(&commands);
	ft_checker_stack_print(commands, a, b, flag_v);
	ft_strdel(&commands);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (!ft_mirror_instructions(&a, &b, ac, av))
		return (0);
	if (ft_is_the_stack_sorted(a, b))
		ft_putendl("\033[1;32mOK\033[0m");
	else
		ft_putendl("\033[1;31mKO\033[0m");
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
