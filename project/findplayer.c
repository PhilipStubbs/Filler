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

char	*findplayer(m_line *node, int fd)
{
	char	*line;

    get_next_line(fd, &line); 
	while(strstr(line, "exec") == NULL)
		get_next_line(fd, &line);
	if (ft_strstr(line, "p1"))
	{
		node->player = 1;
		node->piece = 'o';
	}
	else
	{
		node->player = 2;
		node->piece = 'x';
	}
	return (BOT_NAME);
}
