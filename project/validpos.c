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

// int	countstars(m_line *node)
// {
// 	int	i;
// 	int	l;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	l = 0;
// 	while (l < node->token->sizey)
// 	{
// 		i = 0;
// 		while (i < node->token->sizex)
// 		{
// 			if (node->token->mdhold[l][i] == '*')
// 			{
// 				count++;
// 			}
// 			i++;
// 		}
// 		l++;
// 	}
// 	return(count);
// }

// int	returnval(m_line *node ,int omp, int count)
// {
// 	int	stars;
// 	stars = countstars(node);
// 	if (omp != 1 || count != stars)
// 		return (0);
// 	return (1);
// }

// int	validpos(m_line *node, int y, int x)
// {
// 	int	i;
// 	int	l;
// 	int	omp;
// 	int	count; 

// 	l = 0;
// 	omp = 0;
// 	count = 0;
// 	while (l < node->token->sizey)
// 	{
// 		i = 0;
// 		while (i < node->token->sizex)
// 		{
// 			if (node->token->mdhold[l][i] == '*' && (y+l >= 0 && x+i >= 0) && (y+l < node->grid->sizey && x+i < node->grid->sizex))
// 				count++;
// 			if (node->token->mdhold[l][i] == '*' && (node->grid->mdhold[y+l][x+i] == node->piece || node->grid->mdhold[y+l][x+i] == node->piece - 32))
// 				omp++;
// 			if ((node->grid->mdhold[y+l][x+i] == node->enem || node->grid->mdhold[y+l][x+i] == node->enem -32) && node->token->mdhold[l][i] == '*')
// 				return (0);
// 			i++;
// 		}
// 		l++;
// 		if ( y + l  >= node->grid->sizey)
// 			break ;
// 	}
// 	return(returnval(node ,omp, count));
// }















int	countstars(m_line *node)
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
	return(count);
}

int	returnval(m_line *node ,int omp, int count)
{
	int	stars;
	stars = countstars(node);
	if (omp != 1 || count != stars)
		return (0);
	return (1);
}

int	xcheckstar(m_line *node, int l, int i)
{
	int	count;
	int	x;
	int	y;

	x = node->token->tempx;
	y = node->token->tempy;
	count = 0;

	if (node->token->mdhold[l][i] == '*' && (y+l >= 0 && x+i >= 0) &&
		(y+l < node->grid->sizey && x+i < node->grid->sizex))
				count++;
	return (count);
}

int	xcheckomp(m_line *node, int l, int i)
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
		(hold[y+l][x+i] == node->piece || hold[y+l][x+i] == node->piece - 32))
				omp++;
	return (omp);
}

int	validpos(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int	omp;
	int	count; 

	l = 0;
	omp = 0;
	count = 0;
	node->token->tempy = y;
	node->token->tempx = x;
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			count += xcheckstar(node, l, i);
			omp += xcheckomp(node, l, i);
			if ((node->grid->mdhold[y+l][x+i] == node->enem || node->grid->mdhold[y+l][x+i] == node->enem -32) && node->token->mdhold[l][i] == '*')
				return (0);
			i++;
		}
		l++;
		if (y + l  >= node->grid->sizey)
			break ;
	}
	return(returnval(node ,omp, count));
}


