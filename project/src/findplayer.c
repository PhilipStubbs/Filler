/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:31:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/15 12:31:57 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*findplayer(t_phill *node, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	while (strstr(line, "exec") == NULL)
		get_next_line(fd, &line);
	if (ft_strstr(line, "p1"))
	{
		node->player = 1;
		node->piece = 'o';
		node->enem = 'x';
	}
	else
	{
		node->player = 2;
		node->piece = 'x';
		node->enem = 'o';
	}
	return (BOT_NAME);
}
