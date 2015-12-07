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
	t_minos = (char **)malloc(sizeof(char*) * 27);
	while (file_content[i] != '\0')
	{
		if (i % 21 == 0)
		{
			t_minos[j] = ft_strdup(t_mino_verif(ft_strsub(
							file_content, i - 21, 20), j));
			j++;
		}
		i++;
	}
	if (file_content[i] == '\0')
		t_minos[j] = ft_strdup(t_mino_verif(ft_strsub(
						file_content, i - 21, 20), j));
	t_minos[j + 1] = NULL;
	t_algo(t_minos);
	free(t_minos[0]);
	free(t_minos[1]);
	free(t_minos[2]);
	free(t_minos[3]);
	free(t_minos);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fillit(av[1]);
	else
		ft_error();
	return (0);
}
	/* leaks fillit avec line ci dessous
	while (1); */
