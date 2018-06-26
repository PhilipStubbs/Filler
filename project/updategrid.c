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
	// ft_putendl_fd("beforesplit", 2);
	splitstr = ft_split(line, ' ');
	// ft_putendl_fd("AFRERTplit", 2);
	while (line[i])
	{

		// node->grid->mdhold[l] = ft_strdup(splitstr[1]);
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
	// line = ft_strnew(1);
	// ft_strclr(line);
	
	get_next_line(fd, &line);
	ft_putendl_fd(line, 2);
	while(ft_strstr(line, "000") == NULL)
	{
		// ft_putendl_fd(line, 2);
		get_next_line(fd, &line);
	}
		while(i < node->grid->sizey )
	{
		ft_strclr(node->grid->mdhold[i]);
		i++;
	}
	i = 0;
	// ft_putendl_fd("AFTER GNL", 2);
	while(i < node->grid->sizey -1)
	{
		intogrid(node, line, i);
		get_next_line(fd, &line);
		i++;
	}
	intogrid(node, line, i);

	free(line);
	return (1);
}