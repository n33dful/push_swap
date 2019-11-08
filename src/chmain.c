#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	char buf[21];
	int i;

	i = 1;
	read(0, buf, 21);
	write(1, buf, 21);
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
	return (0);
}