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

int	returnval(int omp, int count, int stars)
{
	if (omp != 1 || count != stars)
	{
		return (0);
	}
	return (1);
}

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

int	validpos(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int	omp;
	int	stars;
	int	count;
	// int	*yx;

	l = 0;
	omp = 0;
	stars = countstars(node);
	// write(1, "X\n", 2);
	count = 0;

	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			ft_putendl_fd("A", 2);
			if (node->token->mdhold[l][i] == '*' && (node->grid->mdhold[y+l][x+i] == node->piece ||node->grid->mdhold[y+l][x+i] == node->piece - 32))
				omp++;
			ft_putendl_fd("B", 2);
			if (node->grid->mdhold[y+l][x+i] == node->enem || node->grid->mdhold[y+l][x+i] == node->enem -32)
				return (0);
			ft_putendl_fd("C", 2);
			if (node->token->mdhold[l][i] == '*' && (y+l >= 0 && x+i >= 0) && (y+l < node->token->sizey && x+i < node->token->sizex))
				count++;
			ft_putendl_fd("X", 2);
			i++;
		}
		l++;
	}
	return(returnval(omp, count, stars));

}




// int	returnval(int omp)
// {
// 	if (omp != 1)
// 	{
// 		return (0);
// 	}
// 	return (1);
// }

// int	*tobig(m_line *node, int y, int x)
// {
// 	int	i;
// 	int	l;
// 	int	*ret;

// 	i = 0;
// 	l = 0;
// 	ret = ft_memalloc(sizeof(int)* 2);
// 	while (l < node->token->sizey)
// 		{
// 			i = 0;
// 			while (i < node->token->sizex)
// 			{
// 				if (node->token->mdhold[l][i] == '*')
// 				{
// 					ret[0] = y;
// 					ret[1] = x;
// 					return (ret);
// 				}
// 				i++;
// 			}
// 			l++;
// 		}
// 	return (ret);
// }

// int	validpos(m_line *node, int y, int x)
// {
// 	int	i;
// 	int	l;
// 	int	omp;
// 	int	*yx;

// 	l = 0;
// 	omp = 0;
// 	yx = tobig(node, y, x);
// 	if (node->token->sizey + yx[0] > node->grid->sizey || yx[1] + node->token->sizex > node->grid->sizex)
// 		return (0);
// 	while (l < node->token->sizey)
// 	{
// 		i = 0;
// 		while (i < node->token->sizex)
// 		{
// 			if (node->token->mdhold[l][i] == '*' && (node->grid->mdhold[y+l][x+i] == node->piece ||node->grid->mdhold[y+l][x+i] == node->piece - 32))
// 				omp++;
// 			if (node->grid->mdhold[y+l][x+i] == node->enem || node->grid->mdhold[y+l][x+i] == node->enem -32)
// 				return (0);
// 			i++;
// 		}
// 		l++;
// 	}
// 	return(returnval(omp));

// }
