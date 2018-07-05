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
# include "../libft/libft.h"

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
}					t_phill;

int					lineplayerone(t_phill *node, int myy, int myx, char **txy);
int					lineplayertwo(t_phill *node, int myy, int myx, char **txy);
int					forkingplayerone(t_phill *node, int cx, int cy);
int					forkingplayertwo(t_phill *node, int cx, int cy);
int					xcheckenem (t_phill *node, int l, int i);
int					scorecount(t_phill *node, int y, int x);
int					xcheckstar(t_phill *node, int l, int i);
int					xcheckomp(t_phill *node, int l, int i);
int					enemparm(t_phill *node, int l, int i);
int					validpos(t_phill *node, int y, int x);
char				*findplayer(t_phill *node, int fd);
char				*findstart(t_phill *node, char c);
int					updategrid(t_phill *node, int fd);
int					findtoken(t_phill *node, int fd);
int					findgrid(t_phill *node, int fd);
void				placementoutput(int y, int x);
int					getinfo(t_phill *node, int fd);
char				**ft_split(char *str, char c);
int					tokenplacement(t_phill *node);
void				resetheatmap(t_phill *node);
int					linetoenem(t_phill *node);
int					swallow(t_phill *node);
int					skipline(int fd);
#endif
