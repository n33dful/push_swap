#include "../include/push_swap.h"

static void	ft_increase_the_variable_i_and_j(int *i, int *j);
static void	ft_conversion(char **res, char **arr_of_a, char **arr_of_b);

char		*ft_inctruction_optimization(char *comma, char *commb)
{
	char	**arr_of_a;
	char	**arr_of_b;
	char	*res;

	arr_of_a = ft_strsplit(comma, '\n');
	arr_of_b = ft_strsplit(commb, '\n');
	res = ft_strnew(0);
	ft_conversion(&res, arr_of_a, arr_of_b);
	res = ft_combine_instructions(res, "pa");
	ft_delete_array(arr_of_a);
	ft_delete_array(arr_of_b);
	ft_strdel(&comma);
	ft_strdel(&commb);
	return (res);
}

static void	ft_increase_the_variable_i_and_j(int *i, int *j)
{
	(*i) = (*i) + 1;
	(*j) = (*j) + 1;
}

static void	ft_conversion(char **res, char **arr_of_a, char **arr_of_b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr_of_a[i] || arr_of_b[j])
	{
		if (arr_of_a[i] && arr_of_b[j] && \
!ft_strcmp(arr_of_a[i], "ra") && !ft_strcmp(arr_of_b[j], "rb"))
		{
			(*res) = ft_combine_instructions((*res), "rr");
			ft_increase_the_variable_i_and_j(&i, &j);
		}
		else if (arr_of_a[i] && arr_of_b[j] && \
!ft_strcmp(arr_of_a[i], "rra") && !ft_strcmp(arr_of_b[j], "rrb"))
		{
			(*res) = ft_combine_instructions((*res), "rrr");
			ft_increase_the_variable_i_and_j(&i, &j);
		}
		else if (arr_of_a[i])
			(*res) = ft_combine_instructions((*res), arr_of_a[i++]);
		else if (arr_of_b[j])
			(*res) = ft_combine_instructions((*res), arr_of_b[j++]);
	}
}
