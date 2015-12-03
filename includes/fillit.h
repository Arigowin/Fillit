
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
char		*t_mino_verif(char *t_mino);
char		*t_is_pipe(char *t_minoi);
char		*t_is_square(char *t_mino);
char		*t_is_t(char *t_mino);
char		*t_is_s(char *t_mino);
char		*t_isrev_s(char *t_mino);
char		*t_is_l(char *t_mino);
char		*t_isrev_l(char *t_mino);
void		t_algo(char **t_mino);

#endif
