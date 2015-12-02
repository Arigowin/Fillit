#include "fillit.h"

char    *t_is_square(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 12, t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 5] == '#' && t_mino[i + 6] == '#')
			return (1);
		i++;
	}
	return ("##\n##\0");
}

char    *t_is_ipipe(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 3, t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 10] == '#'
				&& t_mino[i + 15] == '#')
			return ("#\n#\n#\n#\0");
		else if (i <= 15, t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 2] == '#' && t_mino[i + 3] == '#')
			return ("####\0");
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
		if (i = 12, t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 4] == '#'
				&& t_mino[i + 5] == '#')
			return (".##\n##\0");
		if (t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 6] == '#'
				&& t_mino[i + 11] == '#')
			return ("#.\n##\n.#\0");
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
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 6] == '#'
				&& t_mino[i + 7] == '#')
			return ("##.\n.##\0");
		if (t_mino[i] == '#' && t_mino[i + 4] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 9] == '#')
			return (".#\n##\n#.");
        i++;
	}
	return (NULL);
}
