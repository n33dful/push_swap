/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:16:20 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:26:46 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"







void		ft_lstloop_create(t_list *lst)
{
	t_list	*pointer;

	if (lst)
	{
		pointer = lst;
		while (lst->next != NULL)
		{
			if (lst->next == pointer)
				return ;
			lst = lst->next;
		}
		lst->next = pointer;
	}
}

void		ft_lstloop_break(t_list *lst)
{
	t_list	*pointer;

	if (lst)
	{
		pointer = lst;
		while (lst->next != pointer)
		{
			if (lst->next == NULL)
				return ;
			lst = lst->next;
		}
		lst->next = NULL;
	}
}








static int		(*reindex_func(t_selem *stack_elem))[2]
{
	static int	index[2];

	if (stack_elem)
	{
		stack_elem->rotates_to_top = index[0]++;
		stack_elem->reverse_rotates_to_top = index[1]--;
	}
	return (&index);
}

static void		ft_reindexing(t_list *stack)
{
	size_t	stack_len;

	stack_len = ft_lstlen(stack);
	if (stack_len)
	{
		(*reindex_func(NULL))[0] = 0;
		if (stack_len == 1)
			(*reindex_func(NULL))[1] = 0;
		else
			(*reindex_func(NULL))[1] = stack_len;
		while (stack)
		{
			reindex_func(stack->content);
			stack = stack->next;
		}
	}
}



static void		ft_set_stack_a(t_list *elem)
{
	t_selem	*stack_elem;

	stack_elem = elem->content;
	stack_elem->in_stack_a = 1;
	stack_elem->in_stack_b = 0;
}

static void		ft_set_stack_b(t_list *elem)
{
	t_selem	*stack_elem;

	stack_elem = elem->content;
	stack_elem->in_stack_a = 0;
	stack_elem->in_stack_b = 1;
}

static void		ft_nullify_trash(t_list *stack)
{
	t_selem	*stack_elem;

	stack_elem = stack->content;
	stack_elem->keep = 1;
	stack_elem->total_turns = 0;
	stack_elem->elem_after = NULL;
	stack_elem->common_turns = 0;
	stack_elem->wedding_mode = -1;
}

static t_selem	*ft_set_next(t_list *stack_sorted)
{
	while (!((t_selem *)stack_sorted->content)->in_stack_a)
		stack_sorted = stack_sorted->next;
	return (stack_sorted->content);
}

static int		ft_compare(int mode, int compare[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (compare[mode] > compare[i])
			return (0);
		i++;
	}
	return (1);
}

static int		ft_find_best_mode(int compare[4])
{
	if (ft_compare(up_and_up_mode, compare))
		return (up_and_up_mode);
	else if (ft_compare(down_and_down_mode, compare))
		return (down_and_down_mode);
	else if (ft_compare(up_and_down_mode, compare))
		return (up_and_down_mode);
	else if (ft_compare(down_and_up_mode, compare))
		return (down_and_up_mode);
	else
		return (-1);
}

static void		ft_calculate_turns(t_selem *stack_elem, int (*compare)[4])
{
	if (stack_elem->rotates_to_top > stack_elem->elem_after->rotates_to_top)
		(*compare)[up_and_up_mode] = stack_elem->rotates_to_top;
	else
		(*compare)[up_and_up_mode] = stack_elem->elem_after->rotates_to_top;
	if (stack_elem->reverse_rotates_to_top > \
stack_elem->elem_after->reverse_rotates_to_top)
		(*compare)[down_and_down_mode] = stack_elem->reverse_rotates_to_top;
	else
		(*compare)[down_and_down_mode] = stack_elem->elem_after->reverse_rotates_to_top;
	(*compare)[up_and_down_mode] = stack_elem->reverse_rotates_to_top + \
stack_elem->elem_after->rotates_to_top;
	(*compare)[down_and_up_mode] = stack_elem->rotates_to_top + \
stack_elem->elem_after->reverse_rotates_to_top;
}

static void		ft_set_turns(int best_mode, int turns_compare[4], t_selem *stack_elem)
{
	if (best_mode == up_and_up_mode)
	{
		stack_elem->total_turns = turns_compare[up_and_up_mode];
		if (stack_elem->rotates_to_top && stack_elem->elem_after->rotates_to_top)
			stack_elem->common_turns = stack_elem->rotates_to_top - \
stack_elem->elem_after->rotates_to_top;
		else
			stack_elem->common_turns = 0;
		if (stack_elem->common_turns < 0)
			stack_elem->common_turns = -1 * stack_elem->common_turns;
		else if (stack_elem->rotates_to_top && \
stack_elem->elem_after->rotates_to_top && stack_elem->common_turns == 0)
			stack_elem->common_turns = stack_elem->total_turns;
	}
	else if (best_mode == down_and_down_mode)
	{
		stack_elem->total_turns = turns_compare[down_and_down_mode];
		if (stack_elem->reverse_rotates_to_top && stack_elem->elem_after->reverse_rotates_to_top)
			stack_elem->common_turns = stack_elem->reverse_rotates_to_top - \
stack_elem->elem_after->reverse_rotates_to_top;
		else
			stack_elem->common_turns = 0;
		if (stack_elem->common_turns < 0)
			stack_elem->common_turns = -1 * stack_elem->common_turns;
		else if (stack_elem->reverse_rotates_to_top && \
stack_elem->elem_after->reverse_rotates_to_top && stack_elem->common_turns == 0)
			stack_elem->common_turns = stack_elem->total_turns;
	}
	else
	{
		stack_elem->total_turns = turns_compare[best_mode];
		stack_elem->common_turns = 0;
	}
	stack_elem->wedding_mode = best_mode;
}

static void		ft_find_place_for_each_elem(t_list *stack_b, t_list *stack_sorted)
{
	t_selem	*stack_elem;
	int		turns_compare[4];
	int		best_mode;

	while (stack_b)
	{
		while (stack_b->content != stack_sorted->content)
			stack_sorted = stack_sorted->next;
		stack_elem = stack_b->content;
		stack_elem->elem_after = ft_set_next(stack_sorted);
		ft_calculate_turns(stack_elem, &turns_compare);
		best_mode = ft_find_best_mode(turns_compare);
		ft_set_turns(best_mode, turns_compare, stack_elem);
		stack_b = stack_b->next;
	}
}








static t_selem	*ft_elem_with_min_turns(t_list *stack)
{
	t_selem	*stack_elem;
	t_selem	*min_elem;
	int		min_turns;

	stack_elem = stack->content;
	min_turns = stack_elem->total_turns;
	min_elem = stack_elem;
	while (stack)
	{
		stack_elem = stack->content;
		if (stack_elem->total_turns < min_turns)
		{
			min_turns = stack_elem->total_turns;
			min_elem = stack_elem;
		}
		stack = stack->next;
	}
	return (min_elem);
}

static void		ft_elem_wedding(t_data *data)
{
	t_selem	*stack_elem;
	int		current_turn;

	current_turn = 0;
	stack_elem = ft_elem_with_min_turns(data->stack_b);
	if (stack_elem->wedding_mode == up_and_up_mode)
	{
		while (current_turn < stack_elem->common_turns)
		{
			ft_stack_command(with_print, "rr", data);
			current_turn++;
		}
		while (current_turn < stack_elem->elem_after->rotates_to_top)
		{
			ft_stack_command(with_print, "ra", data);
			current_turn++;
		}
		while (current_turn < stack_elem->rotates_to_top)
		{
			ft_stack_command(with_print, "rb", data);
			current_turn++;
		}
	}
	else if (stack_elem->wedding_mode == down_and_down_mode)
	{
		while (current_turn < stack_elem->common_turns)
		{
			ft_stack_command(with_print, "rrr", data);
			current_turn++;
		}
		while (current_turn < stack_elem->elem_after->reverse_rotates_to_top)
		{
			ft_stack_command(with_print, "rra", data);
			current_turn++;
		}
		while (current_turn < stack_elem->reverse_rotates_to_top)
		{
			ft_stack_command(with_print, "rrb", data);
			current_turn++;
		}
	}
	if (stack_elem->wedding_mode == up_and_down_mode)
	{
		while (current_turn < stack_elem->reverse_rotates_to_top)
		{
			ft_stack_command(with_print, "rrb", data);
			current_turn++;
		}
		while (current_turn < stack_elem->elem_after->rotates_to_top)
		{
			ft_stack_command(with_print, "ra", data);
			current_turn++;
		}
	}
	else if (stack_elem->wedding_mode == down_and_up_mode)
	{
		while (current_turn < stack_elem->rotates_to_top)
		{
			ft_stack_command(with_print, "rb", data);
			current_turn++;
		}
		while (current_turn < stack_elem->elem_after->reverse_rotates_to_top)
		{
			ft_stack_command(with_print, "rra", data);
			current_turn++;
		}
	}
}





void			ft_stack_wedding(t_data *data)
{
	ft_lstloop_create(data->sorted);
	ft_reindexing(data->stack_a);
	ft_reindexing(data->stack_b);
	ft_lstiter(data->stack_a, ft_set_stack_a);
	ft_lstiter(data->stack_b, ft_set_stack_b);
	while (data->stack_b)
	{
		ft_find_place_for_each_elem(data->stack_b, data->sorted);
		ft_elem_wedding(data);
		ft_stack_command(with_print, "pa", data);
		ft_reindexing(data->stack_a);
		ft_reindexing(data->stack_b);
		ft_lstiter(data->stack_a, ft_set_stack_a);
		ft_lstiter(data->stack_b, ft_set_stack_b);
	}
	ft_lstloop_break(data->sorted);
	ft_lstiter(data->stack_a, ft_nullify_trash);
}





































static void	ft_align_stack(t_data *data)
{
	size_t	mid_index;
	size_t	index;
	char	*cmd;

	index = ((t_selem *)data->stack_a->content)->index;
	mid_index = ft_lstlen(data->stack_a) / 2;
	cmd = index <= mid_index ? "rra" : "ra";
	while (((t_selem *)data->stack_a->content)->index != 0)
		ft_stack_command(with_print, cmd, data);
}

static void	ft_init_data(t_data *data)
{
	data->exit_code = 0;
	data->markup = NULL;
	data->sorted = NULL;
	data->stack_a = NULL;
	data->stack_a_len = 0;
	data->stack_b = NULL;
	data->stack_b_len = 0;
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

int			main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (argc > 1)
	{
		if (!ft_stack_new(argc, argv, &data))
			data.exit_code = -1;
		else if (!ft_stack_indexing(&data))
			data.exit_code = -1;
		else if (!ft_stack_markup(&data))
			data.exit_code = -1;
		else
		{
			ft_stack_divorce(&data);
			ft_stack_wedding(&data);
			ft_align_stack(&data);
		}
	}
	ft_del_data(&data);
	if (data.exit_code == -1)
		ft_putendl("Error");
	return (data.exit_code);
}
