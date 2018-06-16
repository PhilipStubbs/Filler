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

int		findsize(char *line,f_line *node, int fd)
{
	char	**splitline;

	get_next_line(fd, &line);
	while(ft_strstr(line, "Plateau") == NULL)
		get_next_line(fd, &line);
	splitline = ft_split(line, ' ');
	node->gridsizey = ft_atoi(splitline[1]);
	node->gridsizex = ft_atoi(splitline[2]);
	node->grid = (char*)ft_memalloc(sizeof(char) * (node->gridsizey * node->gridsizex));
	if (!node->grid)
		return (-1);
	return (1);
}


void	catintonode(char *line, f_line *node)
{
		char	**splitline;

		splitline = ft_split(line, ' ');
		ft_strcat(node->grid, splitline[1]);
		ft_strcat(node->grid, "|");
		free(splitline);
}

int		findgrid(f_line *node, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if(node->gridsizey == 0 || node->gridsizex == 0)
		findsize(line,node, fd);
	get_next_line(fd, &line);
	while(ft_strstr(line, "000") == NULL)
		get_next_line(fd, &line);
	while(i < node->gridsizey -1)
	{
		catintonode(line, node);
		get_next_line(fd, &line);
		i++;
	}
	catintonode(line, node);
	return (1);
}