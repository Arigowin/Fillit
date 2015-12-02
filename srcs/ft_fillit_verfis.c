#include "fillit.h"

static int		t_grid_verif(char *t_mino)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] != '.' || t_mino[i] != '#')
			exit(0);
		if (t_mino[i] == '#')
			j++;
		i++;
	}
	if (i != 16 || j != 4)
		exit(0);
	return (1);
}

static int		t_mino_verif(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino_true(t_mino) != 1)
			exit(0);
		i++;
	}
	return (1);
}

int				t_grid_valid(char *t_mino)
{
	if (t_grid_verif(t_mino) == 1 && t_mino_verif(t_mino) == 1)
		return (1);
	else
		exit(0);
}
