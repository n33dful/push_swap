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

#include "checker.h"

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

static int	ft_mirror_instructions(int flag_v, t_data *data)
{
	int		gnl_status;
	char	*line;

	line = NULL;
	while ((gnl_status = get_next_line(0, &line)) > 0)
	{
		if (!ft_stack_command(without_print, line, data))
		{
			ft_strdel(&line);
			return (0);
		}
		if (flag_v)
			ft_stack_print(line, data->stack_a, data->stack_b);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (gnl_status == -1)
		return (0);
	return (1);
}

static int	ft_parse_flags(int *argc, char ***argv)
{
	if (ft_strequ((*argv)[1], "-v"))
	{
		*argc -= 1;
		*argv +=1;
		return (1);
	}
	return (0);
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

static void	ft_del_data(t_data *data)
{
	if (data->stack_a)
		ft_lstdel(&(data->stack_a), del_stack_elem);
	if (data->stack_b)
		ft_lstdel(&(data->stack_b), del_stack_elem);
	if (data->sorted)
		ft_lstdel(&(data->sorted), del_stack_elem);
	if (data->markup)
		ft_memdel((void *)(&data->markup));
}

static void	ft_init_data(t_data *data)
{
	data->markup = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->sorted = NULL;
	data->stack_a_len = 0;
	data->stack_b_len = 0;
	data->exit_code = 0;
}

int			main(int argc, char **argv)
{
	t_data	data;
	int		flag_v;

	ft_init_data(&data);
	if (argc == 1)
		return (0);
	flag_v = ft_parse_flags(&argc, &argv);
	if (!ft_stack_new(argc, argv, &data))
		data.exit_code = -1;
	else if (!ft_mirror_instructions(flag_v, &data))
		data.exit_code = -1;
	else if (ft_stack_sorted(data.stack_a, data.stack_b))
		ft_putendl("\033[1;32mOK\033[0m");
	else
		ft_putendl("\033[1;31mKO\033[0m");
	ft_del_data(&data);
	if (data.exit_code == -1)
		ft_putendl("Error");
	return (data.exit_code);
}
