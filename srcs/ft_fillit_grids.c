#include "fillit.h"

void		print_grid(char *grid)
{
	write(1, grid, ft_strlen(grid));
}

int			min_square(int t_minos_nb)
{
	int		side_len;

	side_len = 2;
	while ((t_minos_nb * 4) > (side_len * side_len))
		side_len++;
	return (side_len);
}

int			side_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void		gridset(char *grid, int size)
{
	int		i;

	i = 0;
	while (i < (size * size) + size)
	{
		grid[i] = '.';
		if (i > 0 && (i + 1) % (size + 1) == 0)
			grid[i] = '\n';
		i++;
	}
}

void		resetgrids(char *grid, char *t_mino, int i, int j)
{
	while (grid[i])
	{
		if (grid[i] == ('A' + j))
			grid[i] = '.';
		i++;
	}
	i = 0;
	while (t_mino[i])
	{
		if (t_mino[i] == ('A' + j))
			t_mino[i] += 32;
		i++;
	}
}
