#include "../include/checker.h"

static void	ft_putstacknum(t_stack *stack);
static int	ft_numlen(int num);
static void	ft_putstacks(t_stack *a, t_stack *b);

void		ft_stackprint(t_stack *a, t_stack *b)
{
	ft_putstr("+-------------+-------------+\n");
	ft_putstacks(a, b);
	ft_putstr("+-------------+-------------+\n");
	ft_putstr("|      a      |      b      |\n");
	ft_putstr("+-------------+-------------+\n");
}

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	while (num / 10 > 0)
	{
		num /= 10;
		len++;
	}
	return ((num < 0 ? len + 2 : len + 1));
}

static void	ft_putstacknum(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (i < ((13 - ft_numlen(stack->num)) / 2))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(stack->num);
		i += ft_numlen(stack->num);
		while (i < 13)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

static void	ft_putstacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		ft_putstr("|");
		if (a)
		{
			ft_putstacknum(a);
			a = a->next;
		}
		else
			ft_putstr("             ");
		ft_putchar('|');
		if (b)
		{
			ft_putstacknum(b);
			b = b->next;
		}
		else
			ft_putstr("             ");
		ft_putstr("|\n");
	}
}
