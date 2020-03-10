
#include "push_swap.h"

void    del_stack_elem(void *content, size_t content_size)
{
	if (content_size == sizeof(t_selem))
		ft_memdel(&content);
}