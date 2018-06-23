
#include "filler.h"

int		linetoenem(m_line *node)
{
	int		myx;
	int		myy;
	int		count;
	char	**myxy;
	char	**txy;

	count = 0;
	myxy = ft_split(findstart(node, node->piece), ' ');
	txy = ft_split(findstart(node, node->enem), ' ');
	myx = ft_atoi(myxy[0]);
	myy = ft_atoi(myxy[1]);

	if (node->player == 1)
	{
		write(1, "p1 found\n", 9);
		lineplayerone(node, myy, myx, txy);
	}
	else if (node->player == 2)
	{
		write(1, "p2 found\n", 9);
		lineplayertwo(node, myy, myx, myxy);
	}

	
	return (1);
}