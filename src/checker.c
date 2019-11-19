#include "../include/checker.h"

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

static void	flagv(t_stack *a, t_stack *b, int v, char *command)
{
	if (v)
	{
		ft_putstr("> ------- ");
		ft_putendl(command);
		ft_stackprint(a, b);
		ft_putchar('\n');
	}
}

static void	what_to_do(char *comm, t_stack **a, t_stack **b, int v)
{
	if (ft_strcmp(comm, "sa") == 0)
	{
		swap(a);
	}
	else if (ft_strcmp(comm, "sb") == 0)
	{
		swap(b);
	}
	else if (ft_strcmp(comm, "ss") == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strcmp(comm, "pa") == 0)
	{
		push(b, a);
	}
	else if (ft_strcmp(comm, "pb") == 0)
	{
		push(a, b);
	}
	else if (ft_strcmp(comm, "ra") == 0)
	{
		rotate(a);
	}
	else if (ft_strcmp(comm, "rb") == 0)
	{
		rotate(b);
	}
	else if (ft_strcmp(comm, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(comm, "rra") == 0)
	{
		reverse_rotate(a);
	}
	else if (ft_strcmp(comm, "rrb") == 0)
	{
		reverse_rotate(b);
	}
	else if (ft_strcmp(comm, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	flagv((*a), (*b), v, comm);
}

static void	mirror(char *commands, t_stack **a, t_stack **b, int v)
{
	char	**comm;
	int		i;

	i = 0;
	comm = ft_strsplit(commands, '\n');
	while (comm[i])
	{
		what_to_do(comm[i], a, b, v);
		i++;
	}
	i = 0;
	while (comm[i])
		free(comm[i++]);
	free(comm);
}

static int	is_sorted(t_stack *a, t_stack *b);

int			main(int argc, char **argv)
{
	char	*commands;
	t_stack *a;
	t_stack *b;

	commands = program_output();
	b = NULL;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		if (!(a = ft_stacknew(argc - 1, &argv[1])))
		{
			ft_strdel(&commands);
			ft_putstr("Error\n");
			exit(-1);
		}
		mirror(commands, &a, &b, 1);
	}
	else
	{
		if (!(a = ft_stacknew(argc, &argv[0])))
		{
			ft_strdel(&commands);
			ft_putstr("Error\n");
			exit(-1);
		}
		mirror(commands, &a, &b, 0);
	}
	if (is_sorted(a, b))
		ft_putstr("OK");	
	//ft_putstr("\033[1;32mOK\n\033[0m");
	else
		ft_putstr("KO");
	//ft_putstr("\033[1;31mKO\n\033[0m");
	ft_stackdel(&a);
	ft_stackdel(&b);
	ft_strdel(&commands);
	return (0);
}

static int	is_sorted(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	tmp = a;
	if (b != NULL)
		return (0);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
