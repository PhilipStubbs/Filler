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

char	*findstart(t_phill *node, char c)
{
	int		x;
	int		y;
	char	*ret;
	char	**hold;

	x = 0;
	hold = node->grid->mdhold;
	while (x < node->grid->sizex)
	{
		y = 0;
		while (y < node->grid->sizey)
		{
			if (hold[y][x] == c || hold[y][x] == c - 32)
			{
				ret = ft_strjoin(ft_itoa(x++), " ");
				ft_strcat(ret, ft_itoa(y++));
				return (ret);
			}
			y++;
		}
		x++;
	}
	return (NULL);
}
