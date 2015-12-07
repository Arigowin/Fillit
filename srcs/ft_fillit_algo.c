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

static int		place_t_mino(char *grid, char *t_mino, int size, char mino_nb)
{
	// pk mino_nb ??????? pas besoin on va pas parcourire la liste des mino on veux seulement celui en cour
	// a la place de mino_nb -> l'emplacement atuelle de la grille pour eviter de la reparcourire depuis le debut
	// verifie si il ya la place pour mettre le mino en cour
	// a partir d'un point x de la grid
	int		i;

	i = emplacement_grid;
	while (grid[i])
	{

	}
	return (0);
}

static char		*t_algo_r(char *grid, char **t_mino, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		// On regarde si on est sur un mino ou si on a la place pour poser le mino en cour
		if (grid[i] != '.' || place_t_mino(grid, t_mino[j], size, j) == 0)
			t_algo_r(&grid[i + 1], t_mino, size);
		// si il y'a la place on place le mino
		else if (place_t_mino(grid, t_mino[j], size, j) == 1)
			t_algo_r(&grid[i + 1], (t_mino + 1), size);
	}
	// si plus de place on augmente la grille
	if (t_mino != NULL || grid[i] == '\0')
	{
		// void comment realouer de l'espace et recopier la grille dans cette espace
		grid = ft_strnew(size + 1);
		t_algo_r(&grid[0], &t_mino[j], size + 1);
	}
	return (NULL);
}

void			t_algo(char **t_mino)
{
	char	*grid;

	grid = ft_strnew(21);
	ft_bzero(grid, 21);
	t_algo_r(grid, t_mino, 4);
}
