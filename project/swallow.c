/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swallow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:17:21 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/21 17:17:22 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	resetgrid(m_line *node)
{
	int	i;
	int	l;

	i = 0;
	l = 0;

	while(l < node->grid->sizey)
	{
		i = 0;
		while(i < node->grid->sizex)
		{
			node->heatmap[l][i] = 1;
			i++;
		}
		l++;
	}
}

int		setplayerpieces(m_line *node, char c, int repval)
{
	int		i;
	int		l;

	l = 0;
	i = 0;
	while(l < node->grid->sizey)
	{
		i = 0;
		while(i < node->grid->sizex)
		{
			if (node->grid->mdhold[l][i] == c || node->grid->mdhold[l][i] == c - 32 )
			{
				node->heatmap[l][i] = repval;
			}
			i++;
		}
		l++;
	}
	return (1);
}

int		findwho(m_line *node)
{
	int		repval;
	char	c;

	repval = 2;
	c = node->piece;
	setplayerpieces(node, node->piece ,repval);
	if (node->piece == 'o')
		c = 'x';
	else if (node->piece == 'x')
		c = 'o';
	repval = 0;
	setplayerpieces(node, c ,repval);
	return (1);
}

int		forkout(m_line *node, int cx, int cy)
{	
	int count;
	int	x;
	int	y;

	count = 0;
	x = cx;
	y = cy - 1;
	while (count < node->grid->sizex )
	{
		node->heatmap[cy][x++] = 5;
		node->heatmap[cy - 1][x] = 4;
		if (x == node->grid->sizex)
			break ;
		count++;
	}
	count = 0;
	cx -= 1;
	if (node->grid->sizey == 100)
	{
		while (count < node->grid->sizey)
		{
			node->heatmap[y][cx] = 5;
			cx--;
			node->heatmap[y][cx] = 4;
			cx--;
			node->heatmap[y][cx] = 4;
			y++;
			if (cx == 0 || y == node->grid->sizey)
				return (1);
			count++;
		}
		return (1);
	}
	while (count < node->grid->sizey)
	{
		node->heatmap[y++][cx] = 5;
		node->heatmap[y][cx -1] = 4;
		if (y == node->grid->sizey)
			break ;
		count++;
	}
	return (1);
}

int		forker(m_line *node)
{
	int		myx;
	int		myy;
	int		count;
	char	**myxy;
	char	**txy;

	count = 0;
	write(1 , "before split\n",13);
	myxy = ft_split(findstart(node, node->piece), ' ');
	txy = ft_split(findstart(node, node->enem), ' ');
	myx = ft_atoi(myxy[0]);
	myy = ft_atoi(myxy[1]);
	write(1 , "before line\n",12);

	if (node->grid->sizey == 15)
	{
		while(count++ <= atoi(txy[1]) / 10)
		{
			if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
				node->heatmap[myy][myx] = 5;
			myx++;
			myx++;
			myx++;
			if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
				node->heatmap[myy][myx] = 5;
			if (node->heatmap[myy][myx-2] != 2)
				node->heatmap[myy][myx-2] = 5;
			myy++;
			if (myx == node->grid->sizex || myy == node->grid->sizey )
				break ;
		}
	}


	else if (node->grid->sizey == 24)
	{
		while(count++ <= atoi(txy[1]) / 2)
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
	}
	else if (node->grid->sizey == 100)
	{
		while(count++ <= atoi(txy[1]) / 3)
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
	}
	forkout(node, myx, myy);
	return (1);
}



int		forkmapcreate(m_line *node)
{
	forker(node);
	return (1);
}


void	createmem(m_line *node)
{
	int l;

	l = 0;
	node->heatmap = (int**)malloc(sizeof(int) * (node->grid->sizey * node->grid->sizex));
	while(l <= node->grid->sizey)
	{
		node->heatmap[l] = (int*)malloc(sizeof(int)* node->grid->sizex +1);
		l++;
	}
	resetgrid(node);
	write(1, "resetgrid\n", 10);
	findwho(node);
	write(1, "findwho\n", 8);
	forkmapcreate(node);
}


int	loopnegx(m_line *node, int x, int y)
{
	int	count;

	count = 5;

	while (node->heatmap[y][x] == 1 && count > 2 && !(node->heatmap[y][x] >= 2 && node->heatmap[y][x] <= 5)&& y < node->grid->sizey && x < node->grid->sizex)
	{
		printf("[%d][%d]\n",y,x );
		node->heatmap[y][x] = count;
		x--;
		count--;
	}
	return (1);
}

int	loopposx(m_line *node, int x, int y)
{
	int	count;

	count = 5;

	while (node->heatmap[y][x] == 1 && count > 2 && !(node->heatmap[y][x] >= 2 && node->heatmap[y][x] <= 5)&& y < node->grid->sizey && x < node->grid->sizex)
	{
		printf("[%d][%d]\n",y,x );
		node->heatmap[y][x] = count;
		x++;
		count--;
	}
	return (1);
}

int	loopnegy(m_line *node, int x, int y)
{
	int	count;

	count = 5;

	while (node->heatmap[y][x] == 1 && count > 2 && !(node->heatmap[y][x] >= 2 && node->heatmap[y][x] <= 5)&& y < node->grid->sizey && x < node->grid->sizex)
	{
		printf("[%d][%d]\n",y,x );
		node->heatmap[y][x] = count;
		y--;
		count--;
	}
	return (1);
}
int	loopposy(m_line *node, int x, int y)
{
	int	count;

	count = 5;

	while (node->heatmap[y][x] == 1 && count > 2 && !(node->heatmap[y][x] >= 2 && node->heatmap[y][x] <= 5))
	{	

		printf("[%d][%d]\n",y,x );
		node->heatmap[y][x] = count;
		y++;
		if(y == node->grid->sizey)
			return (1);
		count--;
	}
	write(1, "X\n",2);
	return (1);
}

int	searchandreplace(m_line *node, int s, int r)
{
	int	i;
	int	l;
	int	tempi;
	int templ;

	l = 0;
	while(l < node->grid->sizey)
	{
		i = 0;
		while(i < node->grid->sizex)
		{		
			if (node->heatmap[l][i] == s)
			{
	
				loopnegx(node, i-1, l);
				loopposx(node, i+1, l);
				loopnegy(node, i, l-1);
				loopposy(node, i, l+1);
			}

			i++;
		}
		l++;
	}
	return (1);
}
int	chokenemy(m_line *node, char enem)
{	

	// while (l < 0)
	// {
	searchandreplace(node,0, 5);

	// }
	return(1);
}
int	swallow(m_line *node)
{
	char enem;
	if (node->heatmapcreat == 0)
	{
		createmem(node);
		node->heatmapcreat = 1;
	}
	if (node->piece == 'o')
		enem = 'x';
	else if (node->piece == 'x')
		enem = 'o';

	// findwho(node);
	// write(1, "afterfindwho\n",13);
	chokenemy(node, enem);
	

	return (1);
}