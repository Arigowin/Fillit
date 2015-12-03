#include "fillit.h"
#include <stdio.h>

void		t_algo(char **t_mino)
{
	char	*grid;
	int		i;
	int		j;

	grid = ft_strnew(21);
	ft_bzero(grid, 21);
	j = 0;
	while (t_mino[j])
	{
		printf("%s\n\n", t_mino[j]);
		j++;
	}

}
