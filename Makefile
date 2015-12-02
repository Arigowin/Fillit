NAME = fillit

CPATH = srcs
HPATH = includes
OPATH = objs

CFLAGS = -Wall -Werror -Wextra -I $(HPATH)

HEADER = fillit.h

SRC = fillit.c \
	  ft_fillit_read.c

HFILES = $(patsubst %, $(HPATH)/%, $(HEADER))
CFILES = $(patsubst %, $(CPATH)/%, $(SRC))
OFILES = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Building $@"
	@gcc $(CFLAGS) -o $@ $^

$(OPATH)/%.o: $(CPATH)/%.c $(HFILES)
	@echo "Creeating file $@"
	@gcc $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "Ceating objs directory"
	mkdir $@

clean:
	@echo "Deleting objs"
	@/bin/rm -rf $(OPATH)

fclean: clean
	@echo "Deleting $(NAME)"
	@/bin/rm -f $(NAME)

re: fclean all


# little memo
# $@ = rule's name
# $^ = all the rule dependecies
# $< = only the first dependence
