/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemparm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:24:26 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:24:27 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	loopnegx(t_phill *node, int x, int y, int count)
{
	int	**hm;

	hm = node->heatmap;
	if (x > 0 && y > 0)
	{
		while (count > 3 && !(hm[y][x] == 0 || hm[y][x] == 9 || hm[y][x] == 2)
			&& y < node->grid->sizey && x < node->grid->sizex && y > 0 && x > 0)
		{
			hm[y][x] = count;
			x--;
			count--;
			if (x < 0)
			{
				hm[y][x] = count--;
				return (1);
			}
		}
	}
	return (1);
}

int	loopposx(t_phill *node, int x, int y, int count)
{
	int	**hm;

	hm = node->heatmap;
	if (x > 0 && y > 0)
	{
		while (count > 3 && !(hm[y][x] == 0 || hm[y][x] == 9 || hm[y][x] == 2)
			&& y < node->grid->sizey && x < node->grid->sizex && y > 0 && x > 0)
		{
			hm[y][x] = count;
			x++;
			count--;
			if (x == node->grid->sizex)
			{
				hm[y][x] = count;
				return (1);
			}
		}
	}
	return (1);
}

int	loopnegy(t_phill *node, int x, int y, int count)
{
	int	**hm;

	hm = node->heatmap;
	if (x > 0 && y > 0)
	{
		while (count > 3 && !(hm[y][x] == 0 || hm[y][x] == 9 || hm[y][x] == 2)
			&& y < node->grid->sizey && x < node->grid->sizex && y > 0 && x > 0)
		{
			hm[y][x] = count;
			y--;
			count--;
			if (y < 0)
			{
				hm[y][x] = count;
				return (1);
			}
		}
	}
	return (1);
}

int	loopposy(t_phill *node, int x, int y, int count)
{
	int	**hm;

	hm = node->heatmap;
	if (x > 0 && y > 0)
	{
		while (count > 3 && !(hm[y][x] == 0 || hm[y][x] == 9 || hm[y][x] == 2)
			&& y < node->grid->sizey && x < node->grid->sizex && y > 0 && x > 0)
		{
			hm[y][x] = count;
			y++;
			count--;
			if (y == node->grid->sizey)
			{
				hm[y][x] = count;
				return (1);
			}
		}
	}
	return (1);
}

int	enemparm(t_phill *node, int l, int i)
{
	int	count;

	count = 8;
	loopnegx(node, i - 1, l, count);
	loopposx(node, i + 1, l, count);
	loopnegy(node, i, l - 1, count);
	loopposy(node, i, l + 1, count);
	return (1);
}
