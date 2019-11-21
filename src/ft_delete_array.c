#include "../include/push_swap.h"

void	ft_delete_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
	arr = NULL;
}
