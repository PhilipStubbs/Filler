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
	char			**mdhold;
	int				sizex;
	int				sizey;
}					g_line;

typedef	struct		i_line
{
	int				player;
	int				**heatmap;
	int				heatmapcreat;
	char			piece;
	char			enem;
	g_line			*token;
	g_line			*grid;

}					m_line;

int					lineplayerone(m_line *node, int myy, int myx, char **txy);
int					lineplayertwo(m_line *node, int myy, int myx, char **txy);
int					forkingplayerone(m_line *node, int cx, int cy);
int					forkingplayertwo(m_line *node, int cx, int cy);
int					enemparm(m_line *node, int l, int i);
int					validpos(m_line *node, int y, int x);
char				*findplayer(m_line *node, int fd);
char				*findstart(m_line *node, char c);
int					updategrid(m_line *node, int fd);
int					findtoken(m_line *node, int fd);
int					findgrid(m_line *node, int fd);
char				**ft_split(char *str, char c);

int					linetoenem(m_line *node);
int					swallow(m_line *node);
int					skipline(int fd);

#endif
