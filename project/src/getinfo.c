/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:24:51 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:24:52 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		intog(t_phill *node, char *line, int l)
{
	char	**splitstr;
	int		i;

	i = 0;
	splitstr = ft_split(line, ' ');
	while (line[i])
	{
		node->grid->mdhold[l][i] = splitstr[1][i];
		i++;
	}
}

void		updateg(t_phill *node, char *line, int fd)
{
	int		i;

	i = 0;
	while (i < node->grid->sizey)
	{
		ft_strclr(node->grid->mdhold[i]);
		i++;
	}
	i = 0;
	while (i < node->grid->sizey - 1)
	{
		intog(node, line, i);
		get_next_line(fd, &line);
		i++;
	}
	intog(node, line, i);
	free(line);
}

void		intoto(t_phill *node, char *line, int l)
{
	node->token->mdhold[l] = (char*)ft_memalloc(sizeof(char) *
		node->token->sizex + 1);
	ft_memcpy(node->token->mdhold[l], line, node->token->sizex);
}

void		findto(t_phill *node, char *line, int fd)
{
	char	**splitline;
	int		i;

	if (node->token->mdhold)
		free(node->token->mdhold);
	splitline = ft_split(line, ' ');
	node->token->sizey = ft_atoi(splitline[1]);
	node->token->sizex = ft_atoi(splitline[2]);
	node->token->mdhold = (char**)ft_memalloc(sizeof(char*) *
		(node->token->sizey + 1));
	i = 0;
	while (i < node->token->sizey)
	{
		ft_strclr(node->token->mdhold[i]);
		i++;
	}
	i = 0;
	while (i < node->token->sizey)
	{
		get_next_line(fd, &line);
		intoto(node, line, i);
		i++;
	}
}

int			getinfo(t_phill *node, int fd)
{
	char *line;

	get_next_line(0, &line);
	while (ft_strstr(line, "000") == NULL)
		get_next_line(fd, &line);
	updateg(node, line, fd);
	while (ft_strstr(line, "Piece") == NULL)
		get_next_line(fd, &line);
	findto(node, line, fd);
	return (1);
}
