/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:15:24 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/31 10:01:25 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <curses.h>

void	curvisualizer(t_phill *node)
{
	initscr();
	noecho();
	// curs_set(FALSE);
	mvprintw(1, 1 , "HELLO");
	// sleep(1);

	if (node->playable == 0)
	{
		// return;
		endwin();
	}
}

void	asvisualizer(t_phill *node)
{
	int		i;
	int		l;
	char 	c;

	i = 0;
	l = 0;
	c = (char)254;
	while (l < node->grid->sizey)
	{
		i = 0;
		while (i < node->grid->sizex)
		{
			// ft_putchar_fd(node->grid->mdhold[l][i], 2);
			ft_putchar_fd(0x96, 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		l++;
	}
	usleep(30000);
	ft_putchar_fd('\n', 2);
}