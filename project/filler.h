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

typedef	struct		s_grid
{
	char			**mdhold;
	int				sizex;
	int				sizey;
	int				tempy;
	int				tempx;
}					t_grid;

typedef	struct		s_fill
{
	int				player;
	int				**heatmap;
	int				heatmapcreat;
	char			piece;
	char			enem;
	int				playable;
	t_grid			*token;
	t_grid			*grid;
}					t_fill;

int					lineplayerone(t_fill *node, int myy, int myx, char **txy);
int					lineplayertwo(t_fill *node, int myy, int myx, char **txy);
int					forkingplayerone(t_fill *node, int cx, int cy);
int					forkingplayertwo(t_fill *node, int cx, int cy);
int					xcheckenem (t_fill *node, int l, int i);
int					scorecount(t_fill *node, int y, int x);
int					xcheckstar(t_fill *node, int l, int i);
int					xcheckomp(t_fill *node, int l, int i);
int					enemparm(t_fill *node, int l, int i);
int					validpos(t_fill *node, int y, int x);
char				*findplayer(t_fill *node, int fd);
char				*findstart(t_fill *node, char c);
int					updategrid(t_fill *node, int fd);
int					findtoken(t_fill *node, int fd);
int					findgrid(t_fill *node, int fd);
void				placementoutput(int y, int x);
int					getinfo(t_fill *node, int fd);
char				**ft_split(char *str, char c);
int					tokenplacement(t_fill *node);
void				resetheatmap(t_fill *node);
int					linetoenem(t_fill *node);
int					swallow(t_fill *node);
int					skipline(int fd);
#endif
