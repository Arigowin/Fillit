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
void		print_grid(char *grid);
int			min_square(int t_minos_nb);
int			side_size(char *str);
int			place_mino(char *grid, char *t_mino, int j, int i);
void		gridset(char *grid, int size);
char		*enlargecpy(char *grid, int size);
void		resetgrids(char *grid, char *t_mino, int i, int j);
int			t_algo_r(char **grid, char **t_mino, int i, int size);

#endif
