/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treetolist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:13:16 by cdarci            #+#    #+#             */
/*   Updated: 2020/08/30 19:09:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_memerror(t_list *list, t_list *new)
{
	ft_memdel((void*)(&list));
	ft_memdel((void*)(&new));
	return (NULL);
}

t_list			*ft_treetolist(t_tree *tree)
{
	t_list	*list;
	t_list	*new;

	list = NULL;
	if (tree && tree->left && (new = ft_treetolist(tree->left)))
		ft_lstadd_back(&list, new);
	else if (tree && tree->left && !new)
		return (ft_memerror(list, new));
	if (tree && (new = ft_lstnew(tree->content)))
		ft_lstadd_back(&list, new);
	else if (tree && !new)
		return (ft_memerror(list, new));
	if (tree && tree->right && (new = ft_treetolist(tree->right)))
		ft_lstadd_back(&list, new);
	else if (tree && tree->right && !new)
		return (ft_memerror(list, new));
	return (list);
}
