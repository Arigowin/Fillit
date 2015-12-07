#include "fillit.h"
#include <stdio.h>

static void		print_grid(char *grid)
{
	write(1, grid, ft_strlen(grid));
	write(1, "\n", 1);
}

static int		min_square(int t_minos_nb)
{
	int		side_len;

	side_len = 2;
	while ((t_minos_nb * 4) > (side_len * side_len))
		side_len++;
	return (side_len);
}

static int		place_mino(char *grid, char *t_mino, int size, int i, int j)
{
	int		t;

	t = 0;
	if (i >= 0 && i <= 20 && j >= 0 && j <= ((size * size) + size) &&
			grid[j] == '.' && t_mino[i] >= 'a')
	{
		t_mino[i] -= 32;
		grid[j] = t_mino[i];
		t++;
		t += place_mino(grid, t_mino, size, i + 1, j + 1);
		t += place_mino(grid, t_mino, size, i + 5, j + (size + 1));
		t += place_mino(grid, t_mino, size, i - 1, j - 1);
	}
//	printf("%d\n", t);
	return (t);
}
/*
static char		*ft_enlargecpy(char *grid, int size)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = NULL;
	ft_bzero((tmp  = ft_strnew(size)), size);
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
	return (tmp);
}
*/
void			resetgrids(char *grid, char *t_mino, int i, int j)
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

static void		t_algo_r(char *grid, char **t_mino, int size, int i, int j)
{
//	char	*tmp;
	int		k;

	k = 0;
	while (grid[j] && t_mino[k] != NULL)
	{
		while (!ft_isalpha(t_mino[k][i]))
			i++;
		printf("t_mino[k][i] = %c, grid[j] = %c\n", t_mino[k][i], grid[j]);
		if (place_mino(grid, t_mino[k], size, i, j) != 4)
		{
			resetgrids(grid, t_mino[k], 0, k);
			t_algo_r(grid, t_mino, size, i, j + 1);
		}
//		print_grid(grid);
		k++;
	}
/*	if (t_mino[j] != NULL && grid[i] == '\0')
	{
		tmp = ft_strdup(grid);
		size++;
		grid = ft_enlargecpy(tmp, ((size * size) + size) + 1);
		t_algo_r(grid, t_mino, size + 1, 0, j);
	}*/
}

void			gridset(char *grid, int size)
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

void			t_algo(char **t_mino, int mino_nb)
{
	char	*grid;
	int		size;

	size = min_square(mino_nb);
	grid = ft_strnew((size * size) + size);
	gridset(grid, size);
	/*while(*t_mino)
	{
		printf("%s\n", *t_mino);
		t_mino++;
	}*/
	t_algo_r(grid, t_mino, size, 0, 0);
	print_grid(grid);
}
