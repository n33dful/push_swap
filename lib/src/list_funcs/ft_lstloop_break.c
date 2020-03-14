
#include "libft.h"

void	ft_lstloop_break(t_list *lst)
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
