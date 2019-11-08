#include "../incl/checker.h"

static char	*program_output(void)
{
	char	*line;
	char	*tmp;
	char	buf[21];
	int		rd;

	line = ft_strnew(0);
	while ((rd = read(0, buf, 21)) > 0)
	{
		buf[rd] = '\0';
		tmp = ft_strjoin(line, buf);
		ft_strdel(&line);
		line = tmp;
	}
	return (line);
}

static void	what_to_do(char *comm, t_stack **a, t_stack **b)
{
	if (ft_strcmp(comm, "sa") == 0)
		sa(a);
	else if (ft_strcmp(comm, "sb") == 0)
		sb(b);
	else if (ft_strcmp(comm, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(comm, "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(comm, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(comm, "ra") == 0)
		ra(a);
	else if (ft_strcmp(comm, "rb") == 0)
		rb(b);
	else if (ft_strcmp(comm, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(comm, "rra") == 0)
		rra(a);
	else if (ft_strcmp(comm, "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(comm, "rrr") == 0)
		rrr(a, b);
}

static void	mirror(char *commands, t_stack **a, t_stack **b)
{
	char	**comm;
	int		i;

	i = 0;
	comm = ft_strsplit(commands, '\n');
	while (comm[i])
	{
		what_to_do(comm[i], a, b);
		i++;
	}
	i = 0;
	while (comm[i])
		free(comm[i++]);
	free(comm);
}

int			main(int argc, char **argv)
{
	char	*commands;
	t_stack *a;
	t_stack *b;

	commands = program_output();
	a = create_stack(argc, argv);
	b = NULL;
	mirror(commands, &a, &b);
	if (is_sorted(a, b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	delete_stack(&a);
	ft_strdel(&commands);
	return (0);
}