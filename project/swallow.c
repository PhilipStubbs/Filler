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

int		setplayerpieces(m_line *node, char c,int repval)
{
	int		i;
	int		l;

	l = 0;
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

char	*findstart(m_line *node)
{
	int		x;
	int		y;
	char	*ret;

	x = 0;
	while (x < node->grid->sizex )
	{
		y = 0;
		while (y < node->grid->sizey)
		{
			if(node->grid->mdhold[y][x] == node->piece || node->grid->mdhold[y][x] == node->piece -32)
			{
				x++;
				ret = ft_strjoin(ft_itoa(x++), " ");
				y++;
				ft_strcat(ret, ft_itoa(y++));
				return(ret) ;
			}
			y++;
		}
		x++;
	}
	return (NULL);	
}

int		forkout(m_line *node, int cx, int cy)
{	
	int count;
	int	x;
	int	y;

	count = 0;
	x = cx;
	y = cy - 1;
	while (count < node->grid->sizex / 3)
	{
		node->heatmap[cy][x++] = 5;
		node->heatmap[cy - 1][x] = 4;
		count++;
	}
	count = 0;
	cx -= 1;
	while (count < node->grid->sizey / 3)
	{
		node->heatmap[y++][cx] = 5;
		node->heatmap[y][cx -1] = 4;
		count++;
	}
	return (1);
}

int		forker(m_line *node)
{
	int		x;
	int		y;
	int		count;
	char	**xy;

	count = 0;
	xy = ft_split(findstart(node), ' ');
	x = ft_atoi(xy[0]);
	y = ft_atoi(xy[1]);
	while(count++ <= node->grid->sizey/4)
	{
		if (node->heatmap[y][x] != 2)
			node->heatmap[y][x] = 5;
		x++;
		if (node->heatmap[y][x] != 2)
			node->heatmap[y][x] = 4;
		if (node->heatmap[y][x-2] != 2)
			node->heatmap[y][x-2] = 4;
		y++;
		x++;
	}
	forkout(node, x, y);
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
	node->heatmap = (int**)ft_memalloc(sizeof(*node->heatmap) * node->grid->sizey +1);
	while(l < node->grid->sizey)
	{
		node->heatmap[l] = (int*)ft_memalloc(sizeof(int)* node->grid->sizex);
		l++;
	}
	resetgrid(node);
	findwho(node);
	forkmapcreate(node);
}


int	loopnegx(m_line *node, int x, int y)
{
	int	count;

	count = 7;

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

	count = 7;

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

	count = 7;

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

	count = 7;

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
				// loopposy(node, i, l+1);
				// while (node->heatmap[templ][tempi] == 1 && count > 2 && !(node->heatmap[templ][tempi] >= 2 && node->heatmap[templ][tempi] <= 5)&& templ < node->grid->sizey && tempi < node->grid->sizex)
				// {
				// 	printf("[%d][%d]\n",templ,tempi );
				// 	node->heatmap[templ][tempi] = count;
				// 	tempi--;
				// 	count--;
				// }

				// tempi = i+1;
				// count = 7;
				// while (node->heatmap[templ][tempi] == 1 && count > 2 && !(node->heatmap[templ][tempi] >= 2 && node->heatmap[templ][tempi] <= 5)&& templ < node->grid->sizey && tempi < node->grid->sizex)
				// {
				// 	printf("[%d][%d]\n",templ,tempi );
				// 	node->heatmap[templ][tempi] = count;
				// 	tempi++;
				// 	count--;
				// }
				// tempi = i;
				// templ = l+1;
				// count = 5;
				// while (node->heatmap[templ][tempi] == 1 && count > 2 && !(node->heatmap[templ][tempi] >= 2 && node->heatmap[templ][tempi] <= 5) && templ < node->grid->sizey && tempi < node->grid->sizex)
				// {
				// 	printf("[%d][%d]\n",templ,tempi );
				// 	node->heatmap[templ][tempi] = count;
				// 	templ++;
				// 	count--;
				// }
				// tempi = i;
				// templ = l-1;
				// count = 7;
				// while (node->heatmap[templ][tempi] == 1 && count > 2 && !(node->heatmap[templ][tempi] >= 2 && node->heatmap[templ][tempi] <= 5)&& templ < node->grid->sizey && tempi < node->grid->sizex)
				// {
				// 	printf("[%d][%d]\n",templ,tempi );
				// 	node->heatmap[templ][tempi] = count;
				// 	templ--;
				// 	count--;
				// }
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

	if (!node->heatmap)
	{
		createmem(node);
	}
	if (node->piece == 'o')
		enem = 'x';
	else if (node->piece == 'x')
		enem = 'o';

	findwho(node);
	chokenemy(node, enem);
	

	return (1);
}