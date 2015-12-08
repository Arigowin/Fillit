#include "fillit.h"
#include <stdio.h>

static int		ft_mino_valid(char *t_mino, char mino_nb, int i)
{
	int		token;

	token = 0;
	if (t_mino[i] == '#' && i >= 0 && i <= 20 && token <= 4)
	{
		token++;
		t_mino[i] = mino_nb + 'a';
		token += ft_mino_valid(t_mino, mino_nb, i + 1);
		token += ft_mino_valid(t_mino, mino_nb, i - 1);
		token += ft_mino_valid(t_mino, mino_nb, i + 5);
		token += ft_mino_valid(t_mino, mino_nb, i - 5);
	}
	return (token);
}

static int		mino_grid_verif(char *t_mino, int mino_nb)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '.')
			k++;
		if (t_mino[i] == '#')
			j = ft_mino_valid(t_mino, mino_nb, i);
		i++;
	}
	if (i != 20 || j != 4 || k != 12)
		ft_error();
	return (1);
}

char			*t_mino_verif(char *t_mino, int mino_nb)
{
	if (mino_grid_verif(t_mino, mino_nb) == 1)
		return (t_mino);
	ft_error();
	return (NULL);
}
