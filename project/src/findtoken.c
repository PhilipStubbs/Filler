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

int		intotoken(t_phill *node, char *line, int l)
{
	int	x;

	x = node->token->sizex;
	node->token->mdhold[l] = (char*)ft_memalloc(sizeof(char) * x + 1);
	ft_memcpy(node->token->mdhold[l], line, node->token->sizex);
	return (1);
}

int		findtoken(t_phill *node, int fd)
{
	char	*line;
	char	**splitline;
	int		i;

	if (node->token->mdhold)
		free(node->token->mdhold);
	get_next_line(fd, &line);
	while (ft_strstr(line, "Piece") == NULL)
		get_next_line(fd, &line);
	splitline = ft_split(line, ' ');
	node->token->sizey = ft_atoi(splitline[1]);
	node->token->sizex = ft_atoi(splitline[2]);
	node->token->mdhold = (char**)ft_memalloc(sizeof(char*)
		* (node->token->sizey + 1));
	i = 0;
	while (i < node->token->sizey)
		ft_strclr(node->token->mdhold[i++]);
	i = 0;
	while (i < node->token->sizey)
	{
		get_next_line(fd, &line);
		intotoken(node, line, i);
		i++;
	}
	return (1);
}
