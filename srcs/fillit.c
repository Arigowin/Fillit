/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:55:53 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/02 19:09:34 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	fillit(char *file)
{
	char	*file_content;
	int		i;
	int		j;

	i = 0;
	file_content = t_read(file);
	while (file_content[i])
	{
		while(file_content[i + j])
		{
			if (file_content[i + j] == '\n' && file[i + j - 1] == '\n)
				break;
			j++;
		}
		t_grid_verif(ft_strsub(file_content, i, len));
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		fillit(av[1]);
	}
	return (0);
}
