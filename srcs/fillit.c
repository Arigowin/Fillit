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

	i = 21;
	j = 0;
	file_content = t_read(file);
	t_minos = (char **)malloc(sizeof(char*) * 26);
	while (file_content[i] != '\0')
	{
		if (i % 21 == 0)
		{
			t_minos[j] = ft_strdup(t_mino_verif(ft_strsub(file_content, i - 21, 20)));
			j++;
		}
		i++;
	}
	if (file_content[i] == '\0')
		t_minos[j] = ft_strdup(t_mino_verif(ft_strsub(file_content, i - 21, 20)));
	t_algo(t_minos);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fillit(av[1]);
	else
		ft_error();
	return (0);
}
