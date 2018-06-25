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
int	returnval(int omp)
{
	if (omp == 0 || omp > 1)
		return (0);
	return (1);
}

int	validpos(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int	omp;

	l = 0;
	omp = 0;
		if (node->token->sizey + y > node->grid->sizey ||
		x + node->token->sizex > node->grid->sizex)
			return (0);
		while (l < node->token->sizey)
		{
			i = 0;
			while (i < node->token->sizex)
			{
				if (node->token->mdhold[l][i] == '*' &&
					node->heatmap[y+l][x+i] == 2)
					omp++;
				if (node->heatmap[y+l][x+i] == 0)
					return (0);
				i++;
			}
			l++;
		}
	return(returnval(omp));
}
