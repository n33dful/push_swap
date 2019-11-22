#include "../include/libft.h"

int	ft_isint(const char *str)
{
	long long	num;
	int			is_negative;

	num = 0;
	is_negative = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((is_negative && num < num * 10) || num > num * 10)
			return (0);
		else if (is_negative)
			num = num * 10 - (*str - '0');
		else
			num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' || num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}
