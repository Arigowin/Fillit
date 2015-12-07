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
char		*t_mino_verif(char *t_mino, int l);
void		t_algo(char **t_mino, int mino_nb);

#endif
