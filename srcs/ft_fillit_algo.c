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

char			*t_algo_recu(char *grid, int size)
{

	return (NULL);
}

void			t_algo(char **t_mino)
{
	char	*grid;

	grid = ft_strnew(21);
	ft_bzero(grid, 21);
//	t_algo_recu(grid, 4);
//	if ()
}
