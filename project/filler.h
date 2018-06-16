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

typedef	struct		i_line
{
	int				player;
	char			*grid;
	char			*token;
	int				gridsizex;
	int				gridsizey;
	int				x;
	int				y;

}					f_line;

int					skipline(int fd);
char				*findplayer(f_line *node, int fd);
int					findgrid(f_line *node, int fd);
char				**ft_split(char *str, char c);
int					findtoken(f_line *node, int fd);

#endif
