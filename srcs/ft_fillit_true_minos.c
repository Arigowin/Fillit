
#include "fillit.h"

char    *t_is_square(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 12 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 5] == '#' && t_mino[i + 6] == '#')
			return (ft_strdup("##\n##\0"));
		i++;
	}
	return (NULL);
}

char    *t_is_pipe(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 3 && t_mino[i] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 10] == '#' && t_mino[i + 15] == '#')
			return (ft_strdup("#\n#\n#\n#\0"));
		else if (i <= 15 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 2] == '#' && t_mino[i + 3] == '#')
			return (ft_strdup("####\0"));
		i++;
	}
	return (NULL);
}

char    *t_is_s(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 12 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 4] == '#' && t_mino[i + 5] == '#')
			return (ft_strdup(".##\n##.\0"));
		else if (i <= 7 && t_mino[i] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 6] == '#'	&& t_mino[i + 11] == '#')
			return (ft_strdup("#.\n##\n.#\0"));
		i++;
	}
	return (NULL);
}

char    *t_isrev_s(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 11 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 6] == '#' && t_mino[i + 7] == '#')
			return (ft_strdup("##.\n.##\0"));
		if (i <= 8 && t_mino[i] == '#' && t_mino[i + 4] == '#'
				&& t_mino[i + 5] == '#' && t_mino[i + 9] == '#')
			return (ft_strdup(".#\n##\n#.\0"));
		i++;
	}
	return (NULL);
}
