/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_true_minos2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:15:50 by avacher           #+#    #+#             */
/*   Updated: 2015/12/03 17:38:19 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char    *t_is_l(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 11 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 2] == '#' && t_mino[i + 5] == '#')
			return (ft_strdup("###\n#..\0"));
		else if (i <= 7 && t_mino[i] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 10] == '#' && t_mino[i + 11] == '#')
			return (ft_strdup("#.\n#.\n##\0"));
		else if (i <= 7 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 6] == '#' && t_mino[i + 11] == '#')
			return (ft_strdup("##\n.#\n.#\0"));
		else if (i <= 13 && t_mino[i] == '#' && t_mino[i + 3] == '#'
				&& t_mino[i + 4] == '#' && t_mino[i + 5] == '#')
			return (ft_strdup("..#\n###\0"));
        i++;
	}
	return (NULL);
}

char	*t_isrev_l(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 11 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 2] == '#' && t_mino[i + 7] == '#')
			return (ft_strdup("###\n..#\0"));
		else if (i <= 7 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 5] == '#' && t_mino[i + 10] == '#')
			return (ft_strdup("##\n#.\n#.\n"));
		else if (i <= 8 && t_mino[i] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 9] == '#' && t_mino[i + 10] == '#')
			return (ft_strdup(".#\n.#\n##\0"));
		else if (i <= 11 && t_mino[i] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 6] == '#' && t_mino[i + 7] == '#')
			return (ft_strdup("#..\n###\0"));
        i++;
	}
	return (NULL);
}

char	*t_is_t(char *t_mino)
{
	int		i;

	i = 0;
	while (t_mino[i] != '\0')
	{
		if (i <= 11 && t_mino[i] == '#' && t_mino[i + 1] == '#'
				&& t_mino[i + 2] == '#' && t_mino[i + 6] == '#')
			return (ft_strdup("###\n.#.\0"));
		else if (i <= 7 && t_mino[i] == '#' && t_mino[i + 5] == '#'
				&& t_mino[i + 6] == '#' && t_mino[i + 10] == '#')
			return (ft_strdup("#.\n##\n#.\0"));
		else if (i <= 8 && t_mino[i] == '#' && t_mino[i + 4] == '#'
				&& t_mino[i + 5] == '#' && t_mino[i + 10] == '#')
			return (ft_strdup(".#\n##\n.#\0"));
		else if (i <= 12 &&t_mino[i] == '#' && t_mino[i + 4] == '#'
				&& t_mino[i + 5] == '#' && t_mino[i + 6] == '#')
			return (ft_strdup(".#.\n###\0"));
        i++;
	}
	return (NULL);
}
