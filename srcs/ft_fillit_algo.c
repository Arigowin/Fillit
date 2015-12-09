#include "fillit.h"
#include <stdio.h>

static void		print_grid(char *grid)
{
	write(1, grid, ft_strlen(grid));
}

static int		min_square(int t_minos_nb)
{
	int		side_len;

	side_len = 2;
	while ((t_minos_nb * 4) > (side_len * side_len))
		side_len++;
	return (side_len);
}

static int			side_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i ++;
	return (i);
}

static int		place_mino(char *grid, char *t_mino, int j, int i)
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

static void			gridset(char *grid, int size)
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

static char		*enlargecpy(char *grid, int size)
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

static void			resetgrids(char *grid, char *t_mino, int i, int j)
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

static int		t_algo_r(char **grid, char **t_mino, int i, int size)
{
	int		j;
	int		k;
	char	*cpy_grid;

	if (t_mino[i] == NULL)
		return (1);
	cpy_grid = ft_strdup(*grid);
	j = -1;
	k = -1;
	while ((*grid)[++j])
	{
		while (!ft_isalpha(t_mino[i][++k]));
		if (place_mino(*grid, t_mino[i], j, k) != 4)
		{
			k = 0;
			resetgrids(*grid, t_mino[i], j++, i);
			continue ;
		}
		if (t_algo_r(grid, t_mino, i + 1, size))
			return (1);
		*grid = ft_strdup(cpy_grid);
	}
	free(cpy_grid);
	return (0);
}

void			t_algo(char **t_mino, int mino_nb)
{
	char	*grid;
	int		size;

	size = min_square(mino_nb);
	grid = ft_strnew((size * size) + size);
	gridset(grid, size);
	while (!t_algo_r(&grid, t_mino, 0, size))
	{
		grid = enlargecpy(grid, ++size);
	}
	print_grid(grid);
	free(grid);
}
