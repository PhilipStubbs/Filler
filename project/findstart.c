/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findstarts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:02:42 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/23 12:02:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*findstart(m_line *node, char c)
{
	int		x;
	int		y;
	char	*ret;

	x = 0;
	while (x < node->grid->sizex)
	{
		y = 0;
		while (y < node->grid->sizey)
		{
			if(node->grid->mdhold[y][x] == c || node->grid->mdhold[y][x] == c - 32)
			{
				x++;
				ret = ft_strjoin(ft_itoa(x++), " ");
				y++;
				ft_strcat(ret, ft_itoa(y++));
				printf("findstart : [%d][%d]\n",y, x );
				return(ret) ;
			}
			y++;
		}
		x++;
	}
	return (NULL);	
}