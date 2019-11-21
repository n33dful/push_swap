#include "../include/push_swap.h"

char	*ft_combine_instructions(char *first_inctrustion, char *second_inctrustion)
{
	char	*res;

	res = ft_strjoin(first_inctrustion, second_inctrustion);
	ft_strdel(&first_inctrustion);
	return (res);
}
