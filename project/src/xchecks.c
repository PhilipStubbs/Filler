/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xchecks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:11:43 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/04 12:11:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	xcheckstar(t_phill *node, int l, int i)
{
	int	count;
	int	x;
	int	y;

	x = node->token->tempx;
	y = node->token->tempy;
	count = 0;
	if (node->token->mdhold[l][i] == '*' && (y + l >= 0 && x + i >= 0) &&
		(y + l < node->grid->sizey && x + i < node->grid->sizex))
		count++;
	return (count);
}

int	xcheckomp(t_phill *node, int l, int i)
{
	int		omp;
	int		x;
	int		y;
	char	**hold;

	hold = node->grid->mdhold;
	x = node->token->tempx;
	y = node->token->tempy;
	omp = 0;
	if (node->token->mdhold[l][i] == '*' &&
		(hold[y + l][x + i] == node->piece ||
			hold[y + l][x + i] == node->piece - 32))
		omp++;
	return (omp);
}

int	xcheckenem(t_phill *node, int l, int i)
{
	int		x;
	int		y;
	char	**hold;

	hold = node->grid->mdhold;
	x = node->token->tempx;
	y = node->token->tempy;
	if (y + l >= 0)
	{
		if ((hold[y + l][x + i] == node->enem ||
			hold[y + l][x + i] == node->enem - 32)
			&& node->token->mdhold[l][i] == '*')
			return (0);
	}
	return (1);
}
