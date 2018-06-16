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

int		findtoken(f_line *node, int fd)
{
	char	*line;
	char	**splitline;
	int		x;
	int		y;
	int		i;

	if (node->token)
		ft_strclr(node->token);
	get_next_line(fd, &line);
	while(ft_strstr(line, "Piece") == NULL)
	{
		get_next_line(fd, &line);
			printf("%s\n",line );
	}
	splitline = ft_split(line, ' ');
	y = ft_atoi(splitline[1]);
	x = ft_atoi(splitline[2]);
	node->token = (char*)ft_memalloc(sizeof(char) * (x * y));
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_strcat(node->token, line);
		ft_strcat(node->token, "|");
	}
	return (1);
}