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


int	heatmap(m_line *node, int value)
{
	int		xlimit;
	int		ylimit;
	int		x;
	int		y;
	int 	temp;
	int		v;
	char	piece;
	char 	str;
	// int		i;

	x = 0;
	y = 0;
	xlimit = 40;
	ylimit = 12;
	piece = node->piece;
	v = value;

	// if (node->heatmap[0][0] == '\0')
		creatheatmap(node);
	while (x <= xlimit && node->grid->mdhold[y][x])
	{
		y = 0;
		while (y <= ylimit && node->grid->mdhold[y][x])
		{
			if ((node->grid->mdhold[y][x] == 'O' || node->grid->mdhold[y][x] == 'X') && value == 5)
			{
				temp = x;
				node->heatmap[y][x] = piece;
				while(temp >= 0 && node->heatmap[y][temp] == piece)
					temp--;
				node->heatmap[y][temp] = '5';
				temp = x;
				while(temp <= xlimit && node->heatmap[y][temp] == piece)
					temp++;
				node->heatmap[y][temp] = '5';
				temp = y;
				while(temp >= 0 && node->heatmap[temp][x] == piece)
					temp--;
				node->heatmap[temp][x] = '5';
				temp = y;
				while(temp <= ylimit && node->heatmap[temp][x] == piece)
					temp++;
				node->heatmap[temp][x] = '5';
				// v--;
			}
			 if ((node->heatmap[y][x] <= '5' && node->heatmap[y][x] >= '0'))
			{
				temp = x;
				while (temp >= 0 && (node->heatmap[y][temp] == piece || (node->heatmap[y][temp] <= '5' && node->heatmap[y][temp] >= '0')))
					temp--;
				// printf("%c\n",node->heatmap[y][temp + 1] );
				if (node->heatmap[y][temp+1] != '0')
					node->heatmap[y][temp] = *ft_itoa(ft_atoi(&node->heatmap[y][temp+1])-1);
				else
					node->heatmap[y][temp] = '0';
				temp = x;
				while (temp < xlimit && (node->heatmap[y][temp] == piece || (node->heatmap[y][temp] <= '5' && node->heatmap[y][temp] >= '0')))
					temp++;
				if (node->heatmap[y][temp-1] != '0')
					node->heatmap[y][temp] = *ft_itoa(ft_atoi(&node->heatmap[y][temp-1])-1);
				else
					node->heatmap[y][temp] = '0';
				temp = y;
				while((temp >= 0 && node->heatmap[temp][x] == piece) || (node->heatmap[temp][x] <= '5' && node->heatmap[temp][x] >= '0'))
					temp--;
				// printf("%d	%c\n",temp ,node->heatmap[temp][x] );
					str = node->heatmap[temp +1][x] -1;
				if (str < '0')
					str = '0';
				printf("x[%d]y[%d]	%c\n",x,temp,str);
				// i =
				if(temp > 0)
					node->heatmap[temp][x] = str;
				temp = y;
				while((temp < ylimit && node->heatmap[temp][x] == piece) || (node->heatmap[temp][x] <= '5' && node->heatmap[temp][x] >= '0'))
					temp++;
				str = node->heatmap[temp -1][x] -1;
				if (str < '0')
					str = '0';
				node->heatmap[temp][x] = str;
			}
			y++;
		}
		x++;
	}

	return(1);
}