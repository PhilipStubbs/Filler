/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineplayerone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:25:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:25:04 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		smplayerone(t_phill *node, int myy, int myx, char **txy)
{
	int	count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 50;
	while (count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		if (node->heatmap[myy][myx + 1] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx + 1] = 4;
		myx++;
		myx++;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		myy++;
		if (myx == node->grid->sizex || myy == node->grid->sizey)
			return (1);
	}
	forkingplayerone(node, myx, myy);
	return (1);
}

int		mmplayerone(t_phill *node, int myy, int myx, char **txy)
{
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 20;
	while (count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		myx++;
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 4;
		if (node->heatmap[myy][myx - 2] != 2)
			myy++;
		myx++;
		if (myx == node->grid->sizex || myy == node->grid->sizey)
			break ;
	}
	forkingplayerone(node, myx, myy);
	return (1);
}

int		lmplayerone(t_phill *node, int myy, int myx, char **txy)
{
	int count;
	int	temp;

	count = 0;
	temp = atoi(txy[1]) / 10;
	while (count++ <= temp)
	{
		if (node->heatmap[myy][myx] != 2 && myx < node->grid->sizex)
			node->heatmap[myy][myx] = 5;
		myx--;
		myy--;
		if (myx == node->grid->sizex || myy == node->grid->sizey)
			break ;
	}
	forkingplayertwo(node, myx, myy);
	return (1);
}

int		lineplayerone(t_phill *node, int myy, int myx, char **txy)
{
	if (node->grid->sizey == 15)
		smplayerone(node, myy, myx, txy);
	else if (node->grid->sizey == 24)
	{
		forkingplayerone(node, myx, myy);
		return (1);
	}
	else if (node->grid->sizey == 100)
	{
		lmplayerone(node, myy, myx, txy);
		return (1);
	}
	return (1);
}
