/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findtoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:02:30 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/16 14:02:31 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
int		intotoken(m_line *node, char *line, int l)
{
	node->token->mdhold[l] = (char*)ft_memalloc(sizeof(char)*node->token->sizex);
	ft_strcat(node->token->mdhold[l], line);

	return (1);
}

int		findtoken(m_line *node, int fd)
{
	char	*line;
	char	**splitline;
	int		i;

	get_next_line(fd, &line);
	while(ft_strstr(line, "Piece") == NULL)
		get_next_line(fd, &line);
	splitline = ft_split(line, ' ');
	node->token->sizey = ft_atoi(splitline[1]);
	node->token->sizex = ft_atoi(splitline[2]);
	node->token->mdhold = (char**)ft_memalloc(sizeof(char) *
		(node->token->sizex * node->token->sizey));

	i = 0;
	while (i < node->token->sizey )
	{
		get_next_line(fd, &line);
		intotoken(node, line, i);
		i++;
	}
	node->token->mdhold[i] = NULL;
	return (1);
}
