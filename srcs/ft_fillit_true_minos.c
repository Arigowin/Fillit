#include "fillit.h"

int		t_issquare(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 6] == '#')
			return (1);
		else
			ft_error();
	}
	return (0);
}

int		t_ispipe(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 10] == '#'
				&& t_mino[i + 15] == '#')
			return (1);
		else if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 2] == '#'
				&& t_mino[i + 3] == '#')
			return (1);
		else
			ft_error();
	}
	return (0);
}
