/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scorecount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:07:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/04 12:07:39 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		scorecount(t_phill *node, int y, int x)
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
				score += node->heatmap[y + l][x + i];
			i++;
		}
		l++;
	}
	return (score);
}
