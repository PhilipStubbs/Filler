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
	if (omp != 1)
	{
		// ft_putendl_fd(" NO", 2);
		return (0);
	}
	// ft_putendl_fd(" YES", 2 );
	return (1);
}

int	*tobig(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int	*ret;
	// char *re;

	i = 0;
	l = 0;
	ret = ft_memalloc(sizeof(int)* 2);
	while (l < node->token->sizey)
		{
			i = 0;
			while (i < node->token->sizex)
			{
				if (node->token->mdhold[l][i] == '*')
				{
					ret[0] = y;
					ret[1] = x;
					return (ret);
				}
				i++;
			}
			l++;
		}
		// 		re = ft_strjoin(ft_itoa(ret[0]), " EXIT TOBIG ");
		// ft_strcat(re, ft_itoa(ret[1]));
		// ft_putendl_fd(re, 2);
		// ft_putendl_fd(" ", 2);
	return (ret);
}

int	validpos(m_line *node, int y, int x)
{
	int	i;
	int	l;
	int	omp;
	int	*yx;
	// char	*ret;

	l = 0;
	omp = 0;
	yx = tobig(node, y, x);
		if (node->token->sizey + yx[0] > node->grid->sizey || yx[1] + node->token->sizex > node->grid->sizex)
			return (0);
		while (l < node->token->sizey)
		{
			i = 0;
			while (i < node->token->sizex)
			{
				if (node->token->mdhold[l][i] == '*' && (node->grid->mdhold[y+l][x+i] == node->piece ||node->grid->mdhold[y+l][x+i] == node->piece - 32))
					omp++;
				// node->heatmap[y+l][x+i] == 2)
				if (node->grid->mdhold[y+l][x+i] == node->enem || node->grid->mdhold[y+l][x+i] == node->enem -32)
					return (0);
				i++;
			}
			l++;
		}
		// ret = ft_strjoin(ft_itoa(y), " ");
		// ft_strcat(ret, ft_itoa(x));
		// ret = ft_strjoin(ret, "HERE");
		// ft_putstr_fd(ret, 2);
	return(returnval(omp));

}
