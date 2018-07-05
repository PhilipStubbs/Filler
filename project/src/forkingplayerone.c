/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkingplayerone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:24:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:24:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		bmforking(t_phill *node, int cx, int cy)
{
	if (node->grid->sizey == 100)
	{
		while (1)
		{
			node->heatmap[cy][cx] = 9;
			cx--;
			node->heatmap[cy][cx] = 8;
			cx--;
			cy++;
			if ((cx <= 0 || cy >= node->grid->sizey) ||
				(cy <= 0 || cx >= node->grid->sizex))
				return (1);
		}
	}
	while (1)
	{
		node->heatmap[cy++][cx] = 9;
		if (cy == node->grid->sizey || cx == 0)
			break ;
	}
	return (1);
}

static void		smextrafork(t_phill *node, int x, int y)
{
	int cy;

	cy = y - 1;
	while (1)
	{
		node->heatmap[cy][x++] = 9;
		node->heatmap[y--][x] = 9;
		if (x == node->grid->sizex || y == 0)
			break ;
	}
}

int				forkingplayerone(t_phill *node, int cx, int cy)
{
	int	x;
	int	y;
	int	v;

	x = cx;
	y = cy - 1;
	v = 9;
	if (node->grid->sizey == 15)
		smextrafork(node, cx, cy);
	else
	{
		while (1)
		{
			if (node->grid->sizey == 100)
				v = 15;
			node->heatmap[cy][x++] = v;
			if (x == node->grid->sizex)
				break ;
		}
	}
	bmforking(node, cx - 1, y);
	return (1);
}
