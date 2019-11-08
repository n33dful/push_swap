#include "../incl/checker.h"

void	print_stack(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_putnbr(a->num);
			a = a->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		if (b)
		{
			ft_putnbr(b->num);
			b = b->next;
		}
		else
			ft_putchar(' ');
		ft_putchar('\n');
	}
	ft_putstr("- -\n");
	ft_putstr("a b\n");
}
