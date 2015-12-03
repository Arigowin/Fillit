/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:59:38 by avacher           #+#    #+#             */
/*   Updated: 2015/12/03 12:37:13 by avacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char		*t_is_ipipe(char *t_minoi);
char		*t_is_square(char *t_mino);
char		*t_is_t(char *t_mino);
char		*t_is_s(char *t_mino);
char		*t_isrev_s(char *t_mino);
char		*t_is_l(char *t_mino);
char		*t_isrev_l(char *t_mino);
int			t_grid_valid(char *t_mino);

#endif
