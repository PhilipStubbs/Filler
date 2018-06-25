
#include "filler.h"

int		smplayertwo(m_line *node, int myy, int myx, char **txy)
{	
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 10;
	while(count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		if (node->heatmap[myy][myx-1] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx-1] = 4;
		myx--;
		myx--;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		myy--;
		if (myx == node->grid->sizex || myy == node->grid->sizey )
			return (1) ;
	}
	forkingplayertwo(node, myx, myy);
	return (1);
}

int		mmplayertwo(m_line *node, int myy, int myx, char **txy)
{
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 2;
	while(count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		myx--;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		if (node->heatmap[myy][myx+1] != 2)
			node->heatmap[myy][myx+2] = 4;
		myy--;
		myx--;
		if (myx == node->grid->sizex || myy == node->grid->sizey )
			break ;
	}
	forkingplayertwo(node, myx, myy);
	return (1);
}

int		lmplayertwo(m_line *node, int myy, int myx, char **txy)
{
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 3;
	while(count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		myx--;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		if (node->heatmap[myy][myx-2] != 2)
			node->heatmap[myy][myx-2] = 4;
		myy--;
		if (myx == node->grid->sizex || myy == node->grid->sizey )
			break ;
	}
	forkingplayertwo(node, myx, myy);
	return (1);
}

int		lineplayertwo(m_line *node, int myy, int myx, char **txy)
{
	write( 1, "lineplayertwo\n", 14);
	if (node->grid->sizey == 15)
		smplayertwo(node, myy, myx, txy);
	else if (node->grid->sizey == 24)
	{
		mmplayertwo(node, myy, myx, txy);
		return(1);
	}
	else if (node->grid->sizey == 100)
	{
		lmplayertwo(node, myy, myx, txy);
		return(1);
	}
	return (1);
}

