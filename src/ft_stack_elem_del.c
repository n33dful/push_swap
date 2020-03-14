
#include "push_swap.h"

void    ft_stack_elem_del(void *content, size_t content_size)
{
	if (content_size == sizeof(t_selem))
		ft_memdel(&content);
}