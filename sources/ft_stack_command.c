
#include "push_swap.h"

int	ft_stack_command(int mode, char *cmd, t_list **stack_a, t_list **stack_b)
{
	char	*available_commands;

	available_commands = "sasbssrarbrrpapbrrarrbrrr";
	if (!ft_strlen(cmd) || !ft_strstr(available_commands, cmd))
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
	if (mode == print_mode)
		ft_putendl(cmd);
	return (1);
}
