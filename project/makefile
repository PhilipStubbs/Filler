
NAME = philler.filler

SRC = findgrid.c \
	findplayer.c \
	findtoken.c \
	ft_split.c \
	skipline.c \
	updategrid.c \
	swallow.c \
	findstart.c \
	linetoenem.c \
	lineplayerone.c \
	lineplayertwo.c \
	forkingplayerone.c \
	forkingplayertwo.c \
	validpos.c \
	enemparm.c \
	tokenplacement.c \
	getinfo.c \
	resetheatmap.c \
	main.c \


OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(NAME) $(OBJ) -I. -L. libft.a
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all