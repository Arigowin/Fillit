/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:32:58 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/02 17:48:19 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_list	*t_read(char *file)
{
	int		fd;
	char	buff[BUFF_SIZE];
	char	*fi;
	int		i = 0;
	int		j = 0;
	t_list	*lst;

	lst = NULL;
	fd = open(file, O_RDONLY);
	fi = ft_strnew(2*16);
	while(read(fd, buff, BUFF_SIZE))
	{
		while (i < BUFF_SIZE)
		{
			if (buff[i] && !(buff[i] == '\n' && (buff[i - 1] == '\n' || fi[j - 1] == '\n')))
			{
				fi[j] = buff[i];
				j++;
			}
			else
			{
				if (lst == NULL)
					lst = ft_lstnew(fi, ft_strlen(fi));
				else
					ft_lstpushback(&lst, ft_lstnew(fi, ft_strlen(fi)));
				ft_bzero(fi, ft_strlen(fi));
				j = 0;
			}
			i++;
		}
		i = 0;
	}

	while (lst)
	{
		printf("%ssuivant\n", lst->content);
		lst = lst->next;
	}

	close(fd);
	return (lst);
}
