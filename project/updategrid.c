/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updategrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:08:09 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/18 10:08:10 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		intogrid(m_line *node, char *line, int l)
{
	char **splitstr;
	int i;

	i = 0;
	splitstr = ft_split(line, ' ');
	while (line[i])
	{
		node->grid->mdhold[l][i] = splitstr[1][i];
		i++;
	}
	return (1);
}

int		updategrid(m_line *node, int fd)
{	
	int		i;
	char	*line;

	i = 0;
	get_next_line(fd, &line);
	while(ft_strstr(line, "000") == NULL)
		get_next_line(fd, &line);
	while(i < node->grid->sizey -1)
	{
		intogrid(node, line, i);
		get_next_line(fd, &line);
		i++;
	}
	intogrid(node, line, i);
	return (1);
}