
#include "filler.h"

static int		bmforking(m_line *node, int cx, int cy)
{
	if (node->grid->sizey == 100)
	{
		// while (1)
		// {
			
			
		// 	node->heatmap[cy][cx] = 9;
		// 	cx--;
		// 	node->heatmap[cy][cx] = 8;
		// 	cx--;
		// 	node->heatmap[cy][cx] = 8;
		// 	cy++;
		// 	printf("%d 	%d\n",cy, cx );
		// 	if (cx <= 0 ||  cy >= node->grid->sizey  || cy <= 0 || cx >= node->grid->sizex)
		// 		return (1);
		// }
		while (1)
		{
			node->heatmap[cy][cx] = 9;
			cx++;
			node->heatmap[cy][cx] = 8;
			cx++;
			// node->heatmap[cy][cx] = 8;
			cy--;
			if (cx <= 0 ||  cy >= node->grid->sizey  || cy <= 0 || cx >= node->grid->sizex)
				return (1);
		}
	}
	while (1)
	{
		node->heatmap[cy--][cx] = 5;
		// node->heatmap[cy][cx +1] = 8;
		if (cx == node->grid->sizex || cy == 0)
			break ;
	}
	return (1);
}

int		forkingplayertwo(m_line *node, int cx, int cy)
{	
	int	x;
	int	y;

	x = cx;
	y = cy + 1;
	while (1)
	{
		node->heatmap[cy][x--] = 9;
		// node->heatmap[cy + 1][x] = 8;
		node->heatmap[cy][x] = 9;
		if (x == node->grid->sizex || x == 0)
			break ;
	}
	cx += 1;
	bmforking(node, cx, y);
	return (1);
}
