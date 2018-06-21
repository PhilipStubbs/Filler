/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:07:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/15 12:07:04 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BOT_NAME "philler"
# include "libft/libft.h"
#include <stdio.h>

typedef	struct		u_line
{
	char			*hold;
	char			**mdhold;
	int				sizex;
	int				sizey;
	int				x;
	int				y;

}					g_line;

typedef	struct		i_line
{
	int				player;
	int				**heatmap;
	char			piece;
	g_line			*token;
	g_line			*grid;

}					m_line;

int					skipline(int fd);
char				*findplayer(m_line *node, int fd);
int					findgrid(m_line *node, int fd);
char				**ft_split(char *str, char c);
int					findtoken(m_line *node, int fd);
int					updategrid(m_line *node, int fd);
int					swallow(m_line *node);

#endif
