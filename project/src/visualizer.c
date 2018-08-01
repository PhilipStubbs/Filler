/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:15:24 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/01 07:54:59 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	printnodenbrbody(t_phill *node, int i, int l)
{
	if (node->heatmap[l][i] == 2)
		ft_putstr_fd("\x1B[34m██\x1B[0m", 2);
	else if (node->heatmap[l][i] == 0)
		ft_putstr_fd("\x1B[36m██\x1B[0m", 2);
	else if (node->heatmap[l][i] >= 8)
		ft_putstr_fd("\x1B[31m██\x1B[0m", 2);
	else if (node->heatmap[l][i] == 7)
		ft_putstr_fd("\x1B[35m██\x1B[0m", 2);
	else if (node->heatmap[l][i] == 6)
		ft_putstr_fd("\x1B[33m██\x1B[0m", 2);
	else if (node->heatmap[l][i] <= 5 && node->heatmap[l][i] >= 3)
		ft_putstr_fd("\x1B[32m██\x1B[0m", 2);
	else if (node->heatmap[l][i] == 1)
		ft_putstr_fd("\x1B[37m⬜\x1B[0m", 2);
}

void	printnodenbr(t_phill *node)
{
	int i;
	int	l;

	i = 0;
	l = 0;
	while (l < node->grid->sizey)
	{
		i = 0;
		while (i < node->grid->sizex)
		{
			printnodenbrbody(node, i, l);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
	usleep(55000);
	ft_putchar_fd('\n', 2);
}

void	asvisualizer(t_phill *node)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (l < node->grid->sizey)
	{
		i = 0;
		while (i < node->grid->sizex)
		{
			if (node->grid->mdhold[l][i] == node->piece ||
			node->grid->mdhold[l][i] == node->piece - 32)
				ft_putstr_fd("\x1B[34m██\x1B[0m", 2);
			else if (node->grid->mdhold[l][i] == node->enem ||
			node->grid->mdhold[l][i] == node->enem - 32)
				ft_putstr_fd("\x1B[36m██\x1B[0m", 2);
			else if (node->grid->mdhold[l][i] == '.')
				ft_putstr_fd("⬜", 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
	usleep(55000);
	ft_putchar_fd('\n', 2);
}
