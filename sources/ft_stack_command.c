
#include "push_swap.h"

static int	ft_check_rotation_cmd(const char *cmd)
{
	if (ft_strequ(cmd, "sa") || ft_strequ(cmd, "sb") || \
ft_strequ(cmd, "ss") || ft_strequ(cmd, "pa") || ft_strequ(cmd, "pb") || \
ft_strequ(cmd, "ra") || ft_strequ(cmd, "rb") || ft_strequ(cmd, "rr") || \
ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrb") || ft_strequ(cmd, "rrr"))
		return (1);
	return (0);
}

int			ft_stack_command(int mode, char *cmd, \
t_list **stack_a, t_list **stack_b)
{
	if (!ft_check_rotation_cmd(cmd))
		return (0);
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sa"))
		ft_stack_swap(stack_a);
	if (ft_strequ(cmd, "ss") || ft_strequ(cmd, "sb"))
		ft_stack_swap(stack_b);
	if (ft_strequ(cmd, "pa"))
		ft_stack_push(stack_b, stack_a);
	if (ft_strequ(cmd, "pb"))
		ft_stack_push(stack_a, stack_b);
	if (ft_strequ(cmd, "rr") || ft_strequ(cmd, "ra"))
		ft_stack_rotate(stack_a);
	if (ft_strequ(cmd, "rr") || ft_strequ(cmd, "rb"))
		ft_stack_rotate(stack_b);
	if (ft_strequ(cmd, "rrr") || ft_strequ(cmd, "rra"))
		ft_stack_reverse_rotate(stack_a);
	if (ft_strequ(cmd, "rrr") || ft_strequ(cmd, "rrb"))
		ft_stack_reverse_rotate(stack_b);
	if (mode == with_print)
		ft_putendl(cmd);
	return (1);
}
