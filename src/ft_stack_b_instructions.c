#include "../include/push_swap.h"

char	*ft_stack_b_instructions(int count)
{
	char	*comm;
	int		i;

	i = 0;
	comm = ft_strnew(0);
	while (i < (count < 0 ? -1 * count : count))
	{
		comm = (count < 0 ? ft_combine_instructions(comm, "rrb\n") : \
ft_combine_instructions(comm, "rb\n"));
		i++;
	}
	return (comm);
}
