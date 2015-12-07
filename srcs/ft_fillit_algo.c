#include "fillit.h"
#include <stdio.h>

static int		min_square(int t_minos_nb)
{
	int		side_len;

	side_len = 4;
	while ((t_minos_nb * 4) > (side_len * side_len))
		side_len++;
	return (side_len);
}

static int		place_t_mino(char *grid, char **t_mino, int size, char mino_nb)
{
	grid = NULL;
	t_mino = NULL;
	size = 0;
	mino_nb=0;
	return (0);
}

char			*t_algo_r(char *grid, char **t_mino, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		if (grid[i] == '#' || /*fonction qui permet de placer les pieces return nope*/)
			t_algo_r(&grid[i +1], &t_mino[j], size);
		if (/*fonction qui permet de placer les pieces return ok*/)
			t_algo_r(&grid[i + 1], &t_mino[j + 1], size);
	}
	if (t_mino != NULL || grid[i] == '\0')
		t_algo_r(&grid[0], &t_mino[j], size + 1);
	return (NULL);
}

void			t_algo(char **t_mino)
{
	char	*grid;

	grid = ft_strnew(21);
	ft_bzero(grid, 21);
	t_algo_r(grid, t_mino, 4);
}
