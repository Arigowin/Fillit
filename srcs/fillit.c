#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	fillit(char *file)
{
	char	*file_content;
	char	**t_minos;
	int		i;
	int		j;

	i = 20;
	j = 0;
	file_content = t_read(file);
	t_minos = (char **)malloc(sizeof(char*) * 26);
	while (file_content[i])
	{
		if (i % 20 == 0)
		{
			t_minos[j] = t_mino_verif(ft_strsub(file_content, i - 20, i));
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
