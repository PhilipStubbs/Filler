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
	if (node->token->hold)
		free(node->token->hold);

	node->token->hold = (char*)ft_memalloc(sizeof(char) *					//oldway
		(node->token->sizex * node->token->sizey + node->token->sizey));

	node->token->mdhold = (char**)ft_memalloc(sizeof(char) *
		(node->token->sizex * node->token->sizey));

	i = 0;
	printf("%d and %d \n", node->token->sizey, node->token->sizex);
	while (i < node->token->sizey )
	{
		get_next_line(fd, &line);
		
		ft_strcat(node->token->hold, line);
		ft_strcat(node->token->hold, "|");

		intotoken(node, line, i);
		i++;
	}
	return (1);
}
