#include "fillit.h"
#include <stdio.h>

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	fillit(char *file)
{
	char	*file_content;
	int		i;

	i = 20;
	file_content = t_read(file);
	while (file_content[i])
	{
		if (i % 20 == 0)
			t_grid_valid(ft_strsub(file_content, i - 20, i));
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		fillit(av[1]);
	}
	return (0);
}
