
#include "filler.h"

int		linetoenem(m_line *node)
{
	int		myx;
	int		myy;
	char	**myxy;
	char	**txy;

	myxy = ft_split(findstart(node, node->piece), ' ');
	txy = ft_split(findstart(node, node->enem), ' ');
	myx = ft_atoi(myxy[0]);
	myy = ft_atoi(myxy[1]);
	if (node->player == 1)
	{
		lineplayerone(node, myy, myx, txy);
	}
	else if (node->player == 2)
	{
		lineplayertwo(node, myy, myx, myxy);
	}

	
	return (1);
}