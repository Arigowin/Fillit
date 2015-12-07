#include "fillit.h"
#include <stdio.h>
/*
static void		print_grid(char *grid)
{
	write(1, grid, ft_strlen(grid));
}

static int		min_square(int t_minos_nb)
{
	int		side_len;

	side_len = 4;
	while ((t_minos_nb * 4) > (side_len * side_len))
		side_len++;
	return (side_len);
}

static int		place_t_mino(char *grid, char *t_mino, int size, int i)
{
	// pk mino_nb ??????? pas besoin on va pas parcourire la liste des mino on veux seulement celui en cour
	// a la place de mino_nb -> l'emplacement atuelle de la grille pour eviter de la reparcourire depuis le debut
	// verifie si il ya la place pour mettre le mino en cour
	// a partir d'un point x de la grid
	int		j;

	j = 0;
	if (grid[i] == '.' && t_mino[j] != '\0')
	{
		
		place_t_mino(grid, t_mino, size, i);
	}

	// si peut etre placer
	// return (1);
	// sinon
	return (+1);
}

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

static void		t_algo_r(char *grid, char **t_mino, int size, int i, int j)
{
	char	*tmp;

	while (grid[i] && t_mino != NULL)
	{
		// On regarde si on est sur un mino ou si on a la place pour poser le mino en cour
		if (ft_isalpha(grid[i]) || place_t_mino(grid, t_mino[j], size, i) == 0)
			t_algo_r(grid, t_mino, size, i + 1, j);
		// si il y'a la place on place le mino
		else if (place_t_mino(grid, t_mino[j], size, i) == 1)
			t_algo_r(grid, t_mino, size, i + 1, j + 1);
	}
	// si plus de place on augmente la grille
	if (t_mino != NULL || grid[i] == '\0')
	{
		tmp = ft_strdup(grid);
		size++;
		grid = ft_enlargecpy(tmp, ((size * size) + size) + 1);
		t_algo_r(grid, t_mino, size + 1, 0, j);
	}
}
*/
void			t_algo(char **t_mino)
{
	char	*grid;

	grid = ft_strnew(7);
	ft_bzero(grid, 7);
	t_mino = NULL;
	//t_algo_r(grid, t_mino, 2, 0, 0);
	//	print_grid(grid);
}
