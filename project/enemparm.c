
#include "filler.h"

int	loopnegx(m_line *node, int x, int y, int count)
{
	while (count > 5 && !(node->heatmap[y][x] == 0 || node->heatmap[y][x] == 9 || node->heatmap[y][x] == 2) && y < node->grid->sizey 
		&& x < node->grid->sizex)
	{
		node->heatmap[y][x] = count;
		x--;
		count--;
		if (x <= 0)
		{
			node->heatmap[y][x] = count--;
			return (1);
		}
	}
	return (1);
}

int	loopposx(m_line *node, int x, int y, int count)
{

	while (count > 5 && !(node->heatmap[y][x] == 0 || node->heatmap[y][x] == 9|| node->heatmap[y][x] == 2)&& y < node->grid->sizey 
		&& x < node->grid->sizex)
	{
		node->heatmap[y][x] = count;
		x++;
		count--;
		if(x == node->grid->sizex)
		{
			node->heatmap[y][x] = count;
			return (1);
		}	
	}
	return (1);
}

int	loopnegy(m_line *node, int x, int y, int count)
{
	while (count > 5 && !(node->heatmap[y][x] == 0 || node->heatmap[y][x] == 9 || node->heatmap[y][x] == 2) && y < node->grid->sizey &&
	x < node->grid->sizex)
	{
		node->heatmap[y][x] = count;
		y--;
		count--;
		if (y <= 0)
		{
			node->heatmap[y][x] = count;
			return (1);
		}
	}
	return (1);
}
int	loopposy(m_line *node, int x, int y, int count)
{
	while (count > 5 && !(node->heatmap[y][x] == 0 || node->heatmap[y][x] == 9|| node->heatmap[y][x] == 2) && y < node->grid->sizey &&
	x < node->grid->sizex)
	{	
		node->heatmap[y][x] = count;
		y++;
		count--;
		if(y == node->grid->sizey)
		{
			node->heatmap[y][x] = count;
			return (1);
		}
	}
	return (1);
}

int	enemparm(m_line *node, int l, int i)
{
	int	count;
	count = 8;
	loopnegx(node, i-1, l, count);
	// ft_putendl_fd("loopnegx", 2);
	loopposx(node, i+1, l, count);
	// ft_putendl_fd("loopposx", 2);
	loopnegy(node, i, l-1, count);
	// ft_putendl_fd("loopnegy", 2);
	loopposy(node, i, l+1, count);
	// ft_putendl_fd("loopposy", 2);
	return (1);
}