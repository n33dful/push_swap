/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:26:55 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/05 00:03:59 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	ft_stack_sorted(t_list *stack_a)
{
	int		right_index;
	t_elem	*elem;

	right_index = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		elem = stack_a->content;
		if (elem->index != right_index++)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static char	ft_mirror_instructions(int flag_v, t_data *data)
{
	int		gnl_status;
	char	*line;

	line = NULL;
	while ((gnl_status = get_next_line(0, &line)) > 0)
	{
		if (!ft_stack_rotate(SILENT, line, data))
		{
			ft_strdel(&line);
			return (0);
		}
		if (flag_v)
			ft_stack_print(line, data->stack_a, data->stack_b);
		ft_strdel(&line);
	}
	if (gnl_status < 0)
		return (0);
	return (1);
}

static char	ft_parse_flags(int *argc, char ***argv)
{
	if (ft_strequ((*argv)[1], "-v"))
	{
		*argc -= 1;
		*argv += 1;
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	data;
	char	flag_v;

	ft_data_struct_init(&data);
	if (argc > 1)
	{
		flag_v = ft_parse_flags(&argc, &argv);
		if (!ft_stack_new(argc, argv, &data))
			data.exit_code = 1;
		else if (!ft_mirror_instructions(flag_v, &data))
			data.exit_code = 1;
		else if (ft_stack_sorted(data.stack_a))
			ft_putendl_colored("OK", GREEN);
		else
			ft_putendl_colored("KO", RED);
	}
	ft_data_struct_del(&data);
	if (data.exit_code == 1)
		ft_putendl_fd("Error", 2);
	return (data.exit_code);
}
