/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetheatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:20:49 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 11:20:59 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	resetheatmap(t_phill *node)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (l < node->grid->sizey)
	{
		i = 0;
		while (i < node->grid->sizex)
		{
			node->heatmap[l][i] = 1;
			i++;
		}
		l++;
	}
}
