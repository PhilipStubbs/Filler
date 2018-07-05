
NAME = philler.filler

SRC = src/findgrid.c \
	src/findplayer.c \
	src/findtoken.c \
	src/ft_split.c \
	src/skipline.c \
	src/updategrid.c \
	src/swallow.c \
	src/findstart.c \
	src/linetoenem.c \
	src/lineplayerone.c \
	src/lineplayertwo.c \
	src/forkingplayerone.c \
	src/forkingplayertwo.c \
	src/validpos.c \
	src/enemparm.c \
	src/tokenplacement.c \
	src/getinfo.c \
	src/resetheatmap.c \
	src/placementoutput.c \
	src/scorecount.c \
	src/xchecks.c \
	src/main.c \


OBJ = *.o

all: $(NAME)

$(NAME):
	make re -C libft/
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -o $(NAME) $(OBJ) -I. -L. libft/libft.a
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all