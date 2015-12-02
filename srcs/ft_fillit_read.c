/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:32:58 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/02 19:23:56 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*t_read(char *file)
{
	int		fd;
	char	*buff;

	if((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	if(read(fd, buff, BUFF_SIZE) < 0)
		ft_error();

	close(fd);
	return (buff);
}
