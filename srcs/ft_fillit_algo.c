#include "fillit.h"
#include <stdio.h>

void		t_algo(char **t_mino)
{
	char	*grid;
	int		i;
	int		j;

	grid = ft_strnew(21);
	grid = ft_bzero(21);
	while (t_mino[j])
	{
		printf("%s", t_mino[j]);
		j++;
	}

}
