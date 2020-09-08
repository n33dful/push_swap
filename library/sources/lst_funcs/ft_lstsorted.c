/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:01:00 by cdarci            #+#    #+#             */
/*   Updated: 2020/09/02 21:25:15 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsorted(t_list *lst, char (*f)(void *, void *))
{
	t_tree	*tree;
	t_tree	*node;
	t_list	*new;

	tree = NULL;
	while (lst)
	{
		if (!(node = ft_treenew(lst->content)))
		{
			ft_treeclear(&tree, NULL);
			ft_lstclear(&new, NULL);
			break;
		}
		ft_treeadd(&tree, node, f);
		lst = lst->next;
	}
	new = ft_treetolist(tree);
	ft_treeclear(&tree, NULL);
	return (new);
}
