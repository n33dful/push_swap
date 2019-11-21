#include "../include/push_swap.h"

char	*ft_combine_instructions(char *first_inctrustion, char *second_inctrustion)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(second_inctrustion, "\n");
	res = ft_strjoin(first_inctrustion, tmp);
	ft_strdel(&tmp);
	ft_strdel(&first_inctrustion);
	return (res);
}
