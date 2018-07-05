/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:24:16 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:24:17 by pstubbs          ###   ########.fr       */
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
			ft_putnbr_fd(node->heatmap[l][i], 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
}

void	printtokenhold(t_phill *node)
{
	int i;
	int	l;

	i = 0;
	l = 0;
	ft_putchar_fd('[', 2);
	while (l < node->token->sizey)
	{
		i = 0;
		while (i < node->token->sizex)
		{
			ft_putchar_fd(node->token->mdhold[l][i], 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
	ft_putchar_fd(']', 2);
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
			ft_putendl_fd("EXIT", 2);
			return (0);
		}
		getinfo(node, fd);
	}
	return (0);
}
