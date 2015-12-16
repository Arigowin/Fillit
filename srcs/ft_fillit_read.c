/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:56:26 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/13 15:56:28 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*t_read(char *file)
{
	int		fd;
	char	*buff;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) < 0)
		ft_error();
	if (ft_strlen(buff) < 20 || buff[BUFF_SIZE - 1] != '\0')
		ft_error();
	if (buff[ft_strlen(buff) - 1] == '\n' && (buff[ft_strlen(buff) - 2] != '.'
				&& buff[ft_strlen(buff) - 2] != '#'))
		ft_error();
	close(fd);
	return (buff);
}
