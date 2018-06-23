
#include "filler.h"

static int		bmforking(m_line *node, int cx, int cy)
{
	if (node->grid->sizey == 100)
	{
		while (1)
		{
			node->heatmap[cy][cx] = 9;
			cx--;
			node->heatmap[cy][cx] = 8;
			cx--;
			node->heatmap[cy][cx] = 8;
			cy++;
			if (cx == 0 || cy == node->grid->sizey)
				return (1);
		}
	}
	while (1)
	{
		node->heatmap[cy++][cx] = 9;
		node->heatmap[cy][cx -1] = 8;
		if (cy == node->grid->sizey)
			break ;
	}
	return (1);
}

int		forkingplayerone(m_line *node, int cx, int cy)
{	
	int	x;
	int	y;

	x = cx;
	y = cy - 1;
	while (1)
	{
		node->heatmap[cy][x++] = 9;
		node->heatmap[cy - 1][x] = 8;
		if (x == node->grid->sizex)
			break ;
	}
	cx -= 1;
	bmforking(node, cx, y);
	return (1);
}
