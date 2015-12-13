/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:52:34 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/13 15:52:37 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	fillit(char *file)
{
	char	*file_content;
	char	**t_minos;
	int		i;
	int		j;

	i = 20;
	j = 0;
	file_content = t_read(file);
	t_minos = (char **)malloc(sizeof(char*) * 27);
	while (file_content[++i] != '\0')
	{
		if (i % 21 == 0)
		{
			t_minos[j] = ft_strdup(t_mino_verif(ft_strsub(
							file_content, i - 21, 20), j));
			j++;
		}
	}
	if (file_content[i] == '\0')
		t_minos[j] = ft_strdup(t_mino_verif(ft_strsub(
						file_content, i - 21, 20), j));
	t_minos[j + 1] = NULL;
	free(file_content);
	t_algo(t_minos, j);
	ft_free_tbl_s(t_minos);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fillit(av[1]);
	else
		ft_error();
	return (0);
}
