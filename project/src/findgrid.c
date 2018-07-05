/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:28:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/16 11:29:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		findsize(char *line, t_phill *node, int fd)
{
	char	**splitline;
	int		*y;
	int		*x;

	y = &node->grid->sizey;
	x = &node->grid->sizex;
	get_next_line(fd, &line);
	while (ft_strstr(line, "Plateau") == NULL)
		get_next_line(fd, &line);
	splitline = ft_split(line, ' ');
	*y = ft_atoi(splitline[1]);
	*x = ft_atoi(splitline[2]);
	node->grid->mdhold = (char**)ft_memalloc(sizeof(char*) * ((*y) * (*x)));
	if (!node->grid->mdhold)
		return (-1);
	return (1);
}

void	catintonode(char *line, t_phill *node, int i)
{
	char	**splitline;
	int		*x;

	x = &node->grid->sizex;
	splitline = ft_split(line, ' ');
	node->grid->mdhold[i] = (char*)ft_memalloc(sizeof(char) * (*x) + 1);
	ft_strclr(node->grid->mdhold[i]);
	ft_strcat(node->grid->mdhold[i], splitline[1]);
}

int		findgrid(t_phill *node, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (node->grid->sizey == 0 || node->grid->sizex == 0)
		findsize(line, node, fd);
	get_next_line(fd, &line);
	if (!node->grid->mdhold[i])
	{
		while (ft_strstr(line, "000") == NULL)
			get_next_line(fd, &line);
		while (i < node->grid->sizey - 1)
		{
			catintonode(line, node, i);
			get_next_line(fd, &line);
			i++;
		}
		catintonode(line, node, i);
	}
	return (1);
}
