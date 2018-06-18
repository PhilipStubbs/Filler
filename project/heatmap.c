/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:04:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/18 13:04:08 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	creatheatmap(m_line *node)
{
	int i;
	i = 0;

	while (i < node->grid->sizey)
	{
		node->heatmap[i] = (char*)ft_memalloc(sizeof(char) * node->grid->sizex + 1);
		ft_memset(node->heatmap[i], '.', node->grid->sizex);
		node->heatmap[i][node->grid->sizex + 1] = '\0';
		i++;
	}
	node->heatmap[i] = NULL;
	return (1);
}


int	heatmap(m_line *node)
{
	int		xlimit;
	int		ylimit;
	int		x;
	int		y;
	int 	temp;

	x = 0;
	y = 0;
	xlimit = 9;
	ylimit = 9;

	// if (node->heatmap[0][0] == '\0')
		creatheatmap(node);
	while (x <= xlimit && node->grid->mdhold[y][x])
	{
		y = 0;
		while (y <= ylimit && node->grid->mdhold[y][x])
		{
			if (node->grid->mdhold[y][x] == 'O' || node->grid->mdhold[y][x] == 'X')
			{
				write(1, "o", 1);
				temp = x;
				node->heatmap[y][x] = 'x';
				while(temp > 0 && node->heatmap[y][temp] == 'x')
					temp--;
				node->heatmap[y][temp] = '5';
				temp = x;
				while(temp < xlimit && node->heatmap[y][temp] == 'x')
					temp++;
				node->heatmap[y][temp] = '5';
			}
			y++;
		}
		x++;
	}

	return(1);
}