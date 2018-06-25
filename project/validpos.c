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

int	validpos(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int **hm;
	int	omp;

	i = 0;
	l = 0;
	hm = node->heatmap;
	omp = 0;
	if (hm[y][x] != 0)
	{
		if (y < node->token->sizey || x < node->token->sizex)
		{
			write(1," tobig\n", 6);
			return (0);
		}
		printf("y[%d] x[%d] = %d \n",y, x, node->heatmap[y][x]);
		while (l < node->token->sizey)
		{
			i = 0;
			while (i < node->token->sizex)
			{
				// printf("y[%d] x[%d] = %d \n",y, x, node->heatmap[y][x]);
				// printf("y+l[%d] x+i[%d]	[%d]\n",y+l,x+i ,hm[y+l][x+i]);
				if (node->token->mdhold[l][i] == '*' && hm[y+l][x+i] == 2)
					omp++;
				if (omp > 1)
				{
					write(1," omp>1\n", 6);
					return (0);
				}
				if (hm[y+l][x+i] == 0)
				{
					write(1,"hm[y+l][x+i] == 0\n", 18);
					return (0);
				}
				i++;
			}
			l++;
		}
	}
	if (omp == 0)
	{
		write(1," omp=0\n", 6);
		return (0);
	}
	return(1);
}
