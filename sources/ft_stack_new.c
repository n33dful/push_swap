/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:38:44 by cdarci            #+#    #+#             */
/*   Updated: 2019/11/23 16:08:33 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_newstackelem(const char *str_num)
{
	t_selem	stack_elem;
	t_list	*lst;

	lst = NULL;
	if (str_num && !ft_isinteger(str_num))
		return (NULL);
	stack_elem.number = ft_atoi(str_num);
	stack_elem.common_turns = 0;
	stack_elem.elem_after = NULL;
	stack_elem.in_stack_a = 0;
	stack_elem.in_stack_b = 0;
	stack_elem.index = 0;
	stack_elem.keep = 0;
	stack_elem.reverse_rotates_to_top = 0;
	stack_elem.rotates_to_top = 0;
	stack_elem.total_turns = 0;
	stack_elem.wedding_mode = -1;
	if (!(lst = ft_lstnew(&stack_elem, sizeof(t_selem))))
		return (NULL);
	return (lst);
}

static void		ft_arrdel(char ***arr)
{
	size_t	i;

	i = 0;
	if (arr && (*arr))
	{
		while ((*arr)[i])
			ft_strdel(&((*arr)[i++]));
		free((*arr));
		(*arr) = NULL;
	}
}

static t_list	*ft_parse_string(const char *str)
{
	t_list	*stack;
	t_list	*new;
	char	**arr;
	size_t	i;

	i = 0;
	stack = NULL;
	if (!(arr = ft_strsplit(str, ' ')))
		return (NULL);
	while (arr[i])
	{
		if (!(new = ft_newstackelem(arr[i++])))
		{
			ft_arrdel(&arr);
			ft_lstdel(&stack, del_stack_elem);
			return (NULL);
		}
		ft_lstadd_back(&stack, new);
	}
	ft_arrdel(&arr);
	return (stack);
}

static int		ft_checkrepeats(t_list *stack)
{
	t_selem	*stack_elem;
	t_list	*first_elem;
	t_list	*tmp;
	int		num;
	int		count;

	first_elem = stack;
	while (stack)
	{
		tmp = first_elem;
		stack_elem = stack->content;
		num = stack_elem->number;
		count = 0;
		while (tmp)
		{
			stack_elem = tmp->content;
			if (stack_elem->number == num)
				count++;
			tmp = tmp->next;
		}
		if (count != 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int				ft_stack_new(int argc, char **argv, t_data *data)
{
	t_list	*new;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!(new = ft_parse_string(argv[i++])))
		{
			ft_lstdel(&(data->stack_a), del_stack_elem);
			return (0);
		}
		ft_lstadd_back(&(data->stack_a), new);
	}
	if (!ft_checkrepeats(data->stack_a))
		ft_lstdel(&(data->stack_a), del_stack_elem);
	data->stack_a_len = ft_lstlen(data->stack_a);
	return (1);
}
