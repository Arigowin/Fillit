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
	char	**t_minos;
	char	*t_mino;
	int		i;
	int		j;

	i = 20;
	j = 0;
	file_content = t_read(file);
	t_minos = ft_strnew(26);
	t_mino = ft_strnew(20);
	while (file_content[i])
	{
		if (i % 20 == 0)
		{
			/* Recuperer return et passer le tout a t_algo */
			t_minos[j] = t_grid_valid(ft_strsub(file_content, i - 20, i));
			j++;
		}
		i++;
	}
	t_algo(t_minos);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		fillit(av[1]);
	}
	return (0);
}
