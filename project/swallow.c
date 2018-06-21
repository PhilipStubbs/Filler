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
}

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

int		findenemy(m_line *node)
{
	int		i;
	int		l;
	int		repval;
	char	c;

	i = 0;
	l = 0;
	repval = 0;
	if (node->piece == 'o')
		c = 'x';
	else if (node->piece == 'x')
		c = 'o';
	while(l < node->grid->sizey)
	{
		i = 0;
		while(i < node->grid->sizex)
		{
			// if (node->grid->mdhold[l][i] == c || node->grid->mdhold[l][i] == c - 32 );
			if (node->grid->mdhold[l][i] == c)
				node->heatmap[l][i] = repval;
			else if (node->grid->mdhold[l][i] == c - 32)
				node->heatmap[l][i] = repval;
			i++;
		}
		l++;
	}
	return (1);
}
int	findfriendly(m_line *node)
{
	int		i;
	int		l;
	int		repval;
	char	c;

	i = 0;
	l = 0;
	repval = 2;
	c = node->piece;
	while(l < node->grid->sizey)
	{
		i = 0;
		while(i < node->grid->sizex)
		{
			// if (node->grid->mdhold[l][i] == c || node->grid->mdhold[l][i] == c - 32 );
			if (node->grid->mdhold[l][i] == c)
				node->heatmap[l][i] = repval;
			else if (node->grid->mdhold[l][i] == c - 32)
				node->heatmap[l][i] = repval;
			i++;
		}
		l++;
	}
	return (1);
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
			// if (node->grid->mdhold[l][i] == c || node->grid->mdhold[l][i] == c - 32 );
			if (node->grid->mdhold[l][i] == c)
				node->heatmap[l][i] = repval;
			else if (node->grid->mdhold[l][i] == c - 32)
				node->heatmap[l][i] = repval;
			i++;
		}
		l++;
	}
	return (1);
}

int		findwho(m_line *node, char p)
{
	int		repval;
	char	c;

	repval = 2;
	c = node->piece;
	if (p =='e')
	{
		if (node->piece == 'o')
			c = 'x';
		else if (node->piece == 'x')
			c = 'o';
		repval = 0;
	}
	setplayerpieces(node, c ,repval);

	return (1);
}
int	swallow(m_line *node)
{
	// int	i;
	// int	l;

	// i = 0;
	// l = 0;
	if (!node->heatmap)
	{
		createmem(node);
		resetgrid(node);
	}
	// findenemy(node);
	// findfriendly(node);
	findwho(node, 'e');
	findwho(node, 'f');


	return (1);
}