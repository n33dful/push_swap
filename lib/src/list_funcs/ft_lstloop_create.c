
#include "libft.h"

void	ft_lstloop_create(t_list *lst)
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
