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

	findplayer(node, fd);
	findgrid(node, fd);
	findtoken(node, fd);

	printf("%d\n", node->player);
	printf("y: %d 	x: %d\n",node->gridsizey, node->gridsizex);
	printf("[%s]\n",node->grid );
	printf("[%s]\n",node->token);

	// findgrid(node, fd);
	return(0);
}
