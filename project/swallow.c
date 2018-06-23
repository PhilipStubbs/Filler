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
			if (node->grid->mdhold[l][i] == c || 
				node->grid->mdhold[l][i] == c - 32)
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


int		forkmapcreate(m_line *node)
{
	linetoenem(node);
	return (1);
}


void	createmem(m_line *node)
{
	int l;

	l = 0;
	node->heatmap = (int**)malloc(sizeof(int) * 
		(node->grid->sizey * node->grid->sizex));
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
				enemparm(node, l, i);
			}
			i++;
		}
		l++;
	}
	return (1);
}
int	chokenemy(m_line *node)
{	
	searchandreplace(node,0, 5);
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
	// if (node->piece == 'o')
	// 	enem = 'x';
	// else if (node->piece == 'x')
	// 	enem = 'o';

	findwho(node);
	// write(1, "afterfindwho\n",13);
	chokenemy(node);
	return (1);
}