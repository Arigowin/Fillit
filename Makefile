# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/13 15:52:26 by dolewski          #+#    #+#              #
#    Updated: 2015/12/13 15:52:29 by dolewski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	  ft_fillit_verifs.c \
	  ft_fillit_grids.c

OFILES = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Building $@"
	@$(MAKE) -C $(LIBPATH)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "Creating objs directory"
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
