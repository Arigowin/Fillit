
# Add make libft
# and add libft compile in this Makefile
# gcc -Wall -Wextra -Werror -I libft/includes -L libft -lft -I includes srcs/*
#
#

CC =	/usr/bin/clang
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir

NAME = fillit

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes
LIBPATH =	$(ROOT)/libft
LFTHPATH =	$(LIBPATH)/includes

CFLAGS = -Wall -Werror -Wextra -I $(HPATH) -I $(LFTHPATH)
LIBS = -L $(LIBPATH) -lft

SRC = fillit.c \
	  ft_fillit_read.c \
	  ft_fillit_algo.c \
	  ft_fillit_true_minos.c \
	  ft_fillit_true_minos2.c \
	  ft_fillit_verifs.c

OFILES = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Building $@"
	@$(MAKE) -C $(LFTPATH)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "Creeating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "Ceating objs directory"
	@$(MKDIR) $@

clean:
	@echo "Deleting objs"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)

lib.fclean:
	@$(MAKE) -C $(LIbPATH) fclean

re: fclean all

# little memo
# $@ = rule's name
# $^ = all the rule dependecies
# $< = only the first dependence
