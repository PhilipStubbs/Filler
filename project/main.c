#include "filler.h"
#include <stdio.h>

int	main()
{
	f_line *node;
	int fd;

	// fd = open("output.txt", O_RDONLY);
	fd = 0;

	node = (f_line*)malloc(sizeof(f_line));
	if(!node)
		return (0);

	node->gridsizex = 0;
	node->gridsizey = 0;
	// ft_putendl_fd("char const *s", 2);
	findplayer(node, fd);
	ft_putnbr_fd(node->player, 2);
	findgrid(node, fd);
	ft_putstr_fd(node->grid,2);
	// ft_putendl_fd("2", 2);
	findtoken(node, fd);
	ft_putendl_fd("3", 2);

	// printf("[%d]\n", node->player);
	// printf("y: [%d] 	x: [%d]\n",node->gridsizey, node->gridsizex);
	// printf("[%s]\n",node->grid );
	// printf("[%s]\n",node->token);

	return(0);
}
