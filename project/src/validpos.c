/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:08:53 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/25 13:08:54 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		countstars(t_phill *node)
{
	int	i;
	int	l;
	int	count;

	count = 0;
	i = 0;
	l = 0;
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			if (node->token->mdhold[l][i] == '*')
			{
				count++;
			}
			i++;
		}
		l++;
	}
	return (count);
}

int		returnval(t_phill *node, int omp, int count)
{
	int	stars;

	stars = countstars(node);
	if (omp != 1 || count != stars)
		return (0);
	return (1);
}

int		settempxy(t_phill *node, int y, int x)
{
	node->token->tempy = y;
	node->token->tempx = x;
	return (0);
}

int		validpos(t_phill *node, int y, int x)
{
	int	i;
	int	l;
	int	omp;
	int	count;

	l = 0;
	omp = 0;
	count = 0;
	settempxy(node, y, x);
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			count += xcheckstar(node, l, i);
			omp += xcheckomp(node, l, i);
			if (xcheckenem(node, l, i) == 0)
				return (0);
			i++;
		}
		l++;
		if (y + l >= node->grid->sizey)
			break ;
	}
	return (returnval(node, omp, count));
}
