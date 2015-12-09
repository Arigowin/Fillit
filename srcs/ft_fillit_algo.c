#include "fillit.h"

int			place_mino(char *grid, char *t_mino, int j, int i)
{
	int		t;
	int		size;

	size = side_size(grid);
	t = 0;
	if (i >= 0 && i <= 20 && j >= 0 && j <= ((size * size) + size) &&
			grid[j] == '.' && t_mino[i] >= 'a' && t_mino != NULL)
	{
		t_mino[i] -= 32;
		grid[j] = t_mino[i];
		t++;
		t += place_mino(grid, t_mino, j + 1, i + 1);
		t += place_mino(grid, t_mino, j + (size + 1), i + 5);
		t += place_mino(grid, t_mino, j - 1, i - 1);
	}
	return (t);
}

char		*enlargecpy(char *grid, int size)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = NULL;
	ft_bzero((tmp = ft_strnew((size * size) + size)), (size * size) + size);
	gridset(tmp, size);
	while (grid[i])
	{
		if (grid[i] != '\n')
			tmp[j] = grid[i];
		else if (grid[i] == '\n')
		{
			tmp[j] = '.';
			j++;
			tmp[j] = grid[i];
		}
		i++;
		j++;
	}
	free(grid);
	return (tmp);
}

int			t_algo_r(char **grid, char **t_mino, int i, int size)
{
	int		indexes[2];
	char	*cpy_grid;

	if (t_mino[i] == NULL)
		return (1);
	cpy_grid = ft_strdup(*grid);
	indexes[0] = -1;
	indexes[1] = 0;
	while ((*grid)[++indexes[0]])
	{
		while (!ft_isalpha(t_mino[i][indexes[1]]))
			indexes[1]++;
		if (place_mino(*grid, t_mino[i], indexes[0], indexes[1]) != 4)
		{
			indexes[1] = 0;
			resetgrids(*grid, t_mino[i], indexes[0], i);
			continue ;
		}
		if (t_algo_r(grid, t_mino, i + 1, size))
			return (1);
		free(*grid);
		*grid = ft_strdup(cpy_grid);
	}
	free(cpy_grid);
	return (0);
}

void		t_algo(char **t_mino, int mino_nb)
{
	char	*grid;
	int		size;

	size = min_square(mino_nb + 1);
	grid = ft_strnew((size * size) + size);
	gridset(grid, size);
	while (!t_algo_r(&grid, t_mino, 0, size))
	{
		grid = enlargecpy(grid, ++size);
	}
	print_grid(grid);
	free(grid);
}
