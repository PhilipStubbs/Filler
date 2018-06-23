
#include "filler.h"

int		smplayerone(m_line *node, int myy, int myx, char **txy)
{	
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 10;
	while(count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 9;
		myx++;
		myx++;
		myx++;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 9;
		if (node->heatmap[myy][myx-2] != 2)
			node->heatmap[myy][myx-2] = 9;
		myy++;
		if (myx == node->grid->sizex || myy == node->grid->sizey )
			return (1) ;
	}
	return (1);
}

int		mmplayerone(m_line *node, int myy, int myx, char **txy)
{
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 2;
	while(count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		myx++;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		if (node->heatmap[myy][myx-2] != 2)
			node->heatmap[myy][myx-2] = 4;
		myy++;
		myx++;
		if (myx == node->grid->sizex || myy == node->grid->sizey )
			break ;
	}
	forkingplayerone(node, myx, myy);
	return (1);
}

int		lmplayerone(m_line *node, int myy, int myx, char **txy)
{
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 3;
	while(count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		myx++;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		if (node->heatmap[myy][myx-2] != 2)
			node->heatmap[myy][myx-2] = 4;
		myy++;
		if (myx == node->grid->sizex || myy == node->grid->sizey )
			break ;
	}
	forkingplayerone(node, myx, myy);
	return (1);
}

int		lineplayerone(m_line *node, int myy, int myx, char **txy)
{
	if (node->grid->sizey == 15)
		smplayerone(node, myy, myx, txy);
	else if (node->grid->sizey == 24)
	{
		mmplayerone(node, myy, myx, txy);
		return(1);
	}
	else if (node->grid->sizey == 100)
	{
		lmplayerone(node, myy, myx, txy);
		return(1);
	}
	forkingplayerone(node, myx, myy);
	return (1);
}