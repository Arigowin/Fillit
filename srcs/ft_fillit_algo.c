#include "fillit.h"
#include <stdio.h>

static int		min_square(int t_minos_nb)
{
	int		side_len;

	side_len = 4;
	while ((t_minos_nb * 4) > (side_len * side_len))
	{
		side_len++;
	}
	return (side_len);
}

static int			t_algo_r(char **grid, char **piece, int size)
{
	if (t_algo_r(grid, piece + 1,  size) == 1)
		return (1);
	else
	{
		// signifie plus de place
		// donc replacer et piler
		t_algo_r(grid, piece + 1, size);
	}

	return (0);
}

void			t_algo(char **t_mino)
{
	char	*grid;

	grid = ft_strnew(21);
	ft_bzero(grid, 21);
	t_algo_r(&grid, t_mino, 4);
}
