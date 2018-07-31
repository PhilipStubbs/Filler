/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:24:16 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/31 15:21:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_phill	*malloctime(t_phill *node)
{
	node = (t_phill*)malloc(sizeof(t_phill));
	node->heatmapcreat = 0;
	node->playable = 1;
	return (node);
}

t_grid	*mallocgline(void)
{
	t_grid *ret;

	ret = (t_grid*)malloc(sizeof(t_grid));
	ret->mdhold = (char**)malloc(sizeof(char*) * 5);
	ret->sizex = 0;
	ret->sizey = 0;
	ret->tempx = 0;
	ret->tempy = 0;
	return (ret);
}

void	printtokenhold(t_phill *node)
{
	int i;
	int	l;

	i = 0;
	l = 0;
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			if (node->token->mdhold[l][i] == '*')
				ft_putstr_fd("\x1B[34m⬛\x1B[0m", 2);
			else
				ft_putstr_fd("⬜", 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
	ft_putchar_fd('\n', 2);
}

void	visualiser(t_phill *node, int on)
{
	if (on == 1)
		asvisualizer(node);
	if (on == 2)
		printtokenhold(node);
	if (on == 3)
		printnodenbr(node);
	if (on == 4)
	{
		asvisualizer(node);
		printtokenhold(node);
	}
}

int		main(void)
{
	t_phill	*node;
	int		fd;

	fd = 0;
	node = NULL;
	node = malloctime(node);
	node->grid = mallocgline();
	node->token = mallocgline();
	findplayer(node, fd);
	findgrid(node, fd);
	findtoken(node, fd);
	while (node->playable)
	{
		swallow(node);
		tokenplacement(node);
		if (node->playable == 0)
		{
			endwin();
			return (0);
		}
		visualiser(node, 4);
		getinfo(node, fd);
	}
	return (0);
}
