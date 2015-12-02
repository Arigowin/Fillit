#include "fillit.h"


char    *t_is_l(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 2] == '#'
				&& t_mino[i + 5] == '#')
			return ("###\n#\0");
		if (t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 10] == '#'
				&& t_mino[i + 11] == '#')
			return ("#.\n#.\n##\0");
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 6] == '#'
				&& t_mino[i + 11] == '#')
			return ("##\n.#\n.#\0");
		if (t_mino[i] == '#' && t_mino[i + 3] == '#' && t_mino[i + 4] == '#'
				&& t_mino[i + 5] == '#')
			return ("..#\n###\0");
        i++;
	}
	return (NULL);
}

int		t_isrev_l(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 2] == '#'
				&& t_mino[i + 7] == '#')
			return ("..#\n###\0");
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 10] == '#')
			return ("##\n#.\n#.\n");
		if (t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 9] == '#'
				&& t_mino[i + 10] == '#')
			return (".#\n.#\n##\0");
		if (t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 6] == '#'
				&& t_mino[i + 7] == '#')
			return ("#..\n###\0");
        i++;
	}
	return (0);
}

int		t_is_t(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '#' && t_mino[i + 1] == '#' && t_mino[i + 2] == '#'
				&& t_mino[i + 6] == '#')
			return ("###\n.#.\0");
		if (t_mino[i] == '#' && t_mino[i + 5] == '#' && t_mino[i + 6] == '#'
				&& t_mino[i + 10] == '#')
			return ("#.\n##\n#.\0");
		if (t_mino[i] == '#' && t_mino[i + 4] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 10] == '#')
			return (".#\n##\n.#\0");
		if (t_mino[i] == '#' && t_mino[i + 4] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 6] == '#')
			return (".#.\n###\0");
        i++;
	}
	return (0);
}
