/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenplacement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:25:30 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:25:31 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	scorecount(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int score;

	score = 0;
	l = 0;
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			if (node->token->mdhold[l][i] == '*')
				score += node->heatmap[y+l][x+i];
			i++;
		}
		l++;
	}
	return (score);
}

void placementoutput(int y, int x)
{
	char *ret;
	
	ret = ft_strjoin(ft_itoa(y), " ");
	ft_strcat(ret, ft_itoa(x));
	ft_putendl_fd(ret, 1);
	free(ret);
}

int	*findfirststar(m_line *node)
{
	int	x;
	int	y;
	int	*ret;

	y = 0;
	ret = (int*)ft_memalloc(sizeof(int) *2);
	ret[1] = node->token->sizey;
	ret[0] = node->token->sizex;
	while (y < node->token->sizey)
	{
		x = 0;
		while (x < node->token->sizex)
		{
			if (node->token->mdhold[y][x] == '*')
			{	
				if (ret[0] > x)
					ret[0] = x;
				if (ret[1] > y)
					ret[1] = y;
				break;
			}
			x++;
		}
		y++;
	}
	if (y == node->token->sizey)
		ret[1] = 0;
	return (ret);
}

int	cleannode(m_line *node)
{
	node->grid->tempy = 0;
	node->grid->tempx = 0;
	node->token->tempy = 0;
	node->token->tempx = 0;
	return (1);
}

int	positioncheck(m_line *node, int y, int x, int score)
{
	int tempscore;

	tempscore = 0;
	if(validpos(node, y, x) == 1)
	{
		tempscore = scorecount(node, y, x);
		if (tempscore > score)
		{
			score = tempscore;
			node->grid->tempy = y;
			node->grid->tempx = x;
		}
	}
	return (score);
}

int	tokenplacement(m_line *node)
{
	int	x;
	int	y;
	int	score;
	int	*xyneg;

	cleannode(node);
	xyneg = findfirststar(node);
	y = 0 - xyneg[1];
	score = 0;
	while (y < node->grid->sizey)
	{
		x = 0 - xyneg[0];
		while (x < node->grid->sizex)
		{
			score = positioncheck(node, y, x, score);
			x++;
		}
		y++;
	}
	if (score > 0)
		node->playable = 1;
	else
		node->playable = 0;
	placementoutput(node->grid->tempy, node->grid->tempx);
	return (1);
}
