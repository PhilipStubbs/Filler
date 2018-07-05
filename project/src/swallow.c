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

int		setplayerpieces(t_phill *node, char c, int repval)
{
	int		i;
	int		l;

	l = 0;
	i = 0;
	while (l < node->grid->sizey)
	{
		i = 0;
		while (i < node->grid->sizex)
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

int		findwho(t_phill *node)
{
	int		repval;

	repval = 2;
	setplayerpieces(node, node->piece, repval);
	repval = 0;
	setplayerpieces(node, node->enem, repval);
	return (1);
}

void	createmem(t_phill *node)
{
	int l;

	l = 0;
	node->heatmap = (int**)malloc(sizeof(int) *
		(node->grid->sizey * node->grid->sizex));
	while (l <= node->grid->sizey)
	{
		node->heatmap[l] = (int*)malloc(sizeof(int) * node->grid->sizex + 1);
		l++;
	}
	resetheatmap(node);
	findwho(node);
	linetoenem(node);
}

int		findenem(t_phill *node)
{
	int	i;
	int	l;

	l = 0;
	while (l < node->grid->sizey)
	{
		i = 0;
		while (i < node->grid->sizex)
		{
			if (node->heatmap[l][i] == 0)
			{
				enemparm(node, l, i);
			}
			i++;
		}
		l++;
	}
	return (1);
}

int		swallow(t_phill *node)
{
	if (node->heatmapcreat == 0)
	{
		createmem(node);
		node->heatmapcreat = 1;
	}
	findwho(node);
	findenem(node);
	return (1);
}
