#include "fillit.h"

static int		t_grid_verif(char *t_mino)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] != '.' && t_mino[i] != '#' && t_mino[i] != '\n')
			ft_error();
		if (t_mino[i] == '#')
			j++;
		if (t_mino[i] == '.')
			k++;
		i++;
	}
	if (i != 20 || j != 4 || k != 12)
		ft_error();
	return (1);
}

static char		*t_modif(char *t_mino, int l)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (t_mino[i] == '#')
			t_mino[i] = ('A' + l);
		i++;
	}
	return (t_mino);
}

char			*t_mino_verif(char *t_mino, int l)
{
	char	*tmp;

	if (t_grid_verif (t_mino) == 1)
	{
		if ((tmp = t_is_pipe(t_mino)) != NULL)
			return (t_modif(tmp, l));
		if ((tmp = t_is_square(t_mino)) != NULL)
			return (t_modif(tmp, l));
		if ((tmp = t_is_t(t_mino)) != NULL)
			return (t_modif(tmp, l));
		if ((tmp = t_is_s(t_mino)) != NULL)
			return (t_modif(tmp, l));
		if ((tmp = t_isrev_s(t_mino)) != NULL)
			return (t_modif(tmp, l));
		if ((tmp = t_is_l(t_mino)) != NULL)
			return (t_modif(tmp, l));
		if ((tmp = t_isrev_l(t_mino)) != NULL)
			return (t_modif(tmp, l));
	}
	ft_error();
	return (NULL);
}
