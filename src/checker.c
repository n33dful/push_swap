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
		ft_putstr("\033[1;33m>------ ");
		ft_putstr(command);
		ft_stack_print(a, b);
		ft_putendl("\033[0m");
	}
}

static void	ft_what_to_dos(char *comm, t_stack **a, t_stack **b, int v)
{
	if (!ft_strcmp(comm, "sa") || !ft_strcmp(comm, "ss"))
		ft_stack_swap(a);
	if (!ft_strcmp(comm, "sb") || !ft_strcmp(comm, "ss"))
		ft_stack_swap(b);
	if (!ft_strcmp(comm, "pa"))
		ft_stack_push(b, a);
	if (!ft_strcmp(comm, "pb"))
		ft_stack_push(a, b);
	if (!ft_strcmp(comm, "ra") || !ft_strcmp(comm, "rr"))
		ft_stack_rotate(a);
	if (!ft_strcmp(comm, "rb") || !ft_strcmp(comm, "rr"))
		ft_stack_rotate(b);
	if (!ft_strcmp(comm, "rra") || !ft_strcmp(comm, "rrr"))
		ft_stack_reverse_rotate(a);
	if (!ft_strcmp(comm, "rrb") || !ft_strcmp(comm, "rrr"))
		ft_stack_reverse_rotate(b);
	flagv((*a), (*b), v, comm);
}

static void	ft_instruction_executions(char *commands, t_stack **a, t_stack **b, int v)
{
	char	**comm;
	int		i;

	i = 0;
	comm = ft_strsplit(commands, '\n');
	while (comm[i])
	{
		ft_what_to_dos(comm[i], a, b, v);
		i++;
	}
	i = 0;
	ft_delete_array(comm);
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
		if (!(a = ft_stack_new(argc - 1, &argv[1])))
		{
			ft_strdel(&commands);
			ft_putstr("Error\n");
			exit(-1);
		}
		ft_instruction_executions(commands, &a, &b, 1);
	}
	else
	{
		if (!(a = ft_stack_new(argc, &argv[0])))
		{
			ft_strdel(&commands);
			ft_putstr("Error\n");
			exit(-1);
		}
		ft_instruction_executions(commands, &a, &b, 0);
	}
	if (is_sorted(a, b))
		ft_putstr("\033[1;32mOK\n\033[0m");
	else
		ft_putstr("\033[1;31mKO\n\033[0m");
	ft_stack_del(&a);
	ft_stack_del(&b);
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
