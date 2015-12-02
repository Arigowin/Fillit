/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:56:01 by dolewski          #+#    #+#             */
/*   Updated: 2015/12/02 18:53:33 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// exit, open, close, write, read, malloc et free

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libft.h>

# define BUFF_SIZE 546

char		*t_read(char *file);
void		ft_error(void);
void		fillit(char *file);

#endif
