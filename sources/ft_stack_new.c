/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:38:44 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/04 23:08:54 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_new_stack_element(char const *str_num)
{
	t_elem	*elem;
	t_list	*list;

	if (!str_num || !ft_isinteger(str_num))
		return (NULL);
	if (!(elem = (t_elem*)ft_memalloc(sizeof(t_elem))))
		return (NULL);
	elem->common_turns = 0;
	elem->elem_after = NULL;
	elem->in_stack_a = 0;
	elem->in_stack_b = 0;
	elem->index = 0;
	elem->keep = 0;
	elem->number = ft_atoi(str_num);
	elem->reverse_rotates_to_top = 0;
	elem->rotates_to_top = 0;
	elem->total_turns = 0;
	elem->wedding_mode = -1;
	if (!(list = ft_lstnew(elem)))
		ft_memdel((void*)(&elem));
	return (list);
}

static char		ft_stack_elems_compare(void *first, void *second)
{
	return (((t_elem*)first)->number > ((t_elem*)second)->number);
}

static char		ft_parse_string(char const *str, t_data *data)
{
	char	**arr;
	t_tree	*node;
	t_list	*new;
	size_t	i;

	i = 0;
	if (!(arr = ft_strsplit(str, ' ')))
		return (0);
	while (arr[i])
	{
		if ((new = ft_new_stack_element(arr[i++])))
			ft_lstadd_back(&data->stack_a, new);
		if (new && (node = ft_treenew(new->content)))
			ft_treeadd(&data->tree, node, ft_stack_elems_compare);
		if (!new || !node)
		{
			ft_arrdel((void*)(&arr));
			return (0);
		}
		data->stack_a_len++;
	}
	ft_arrdel((void*)(&arr));
	return (1);
}

static char		ft_stack_indexing(t_data *data)
{
	t_elem	*elem;
	t_list	*ptr;
	size_t	i;

	i = 0;
	data->sorted = ft_treetolist(data->tree);
	if (!data->sorted)
		return (0);
	ptr = data->sorted;
	while (ptr->next)
	{
		elem = ptr->content;
		if (elem->number == ((t_elem*)ptr->next->content)->number)
			return (0);
		elem->index = i++;
		ptr = ptr->next;
	}
	((t_elem*)ptr->content)->index = i;
	return (1);
}

char			ft_stack_new(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_parse_string(argv[i++], data))
			return (0);
	}
	if (!ft_stack_indexing(data))
		return (0);
	ft_treeclear(&data->tree, NULL);
	return (1);
}
