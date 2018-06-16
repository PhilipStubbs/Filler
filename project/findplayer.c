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

char	*findplayer(f_line *node, int fd)
{
	char	*line;
 	//int 	i;

    // i = 0;
	 //while (i < 6)
	// {
	 //	skipline(fd);
	// 	i++;
	// }
    get_next_line(fd, &line); 
	while(strstr(line, "exec")== NULL)
		get_next_line(fd, &line);
	if (ft_strstr(line, BOT_NAME))
		node->player = 1;
	else
		node->player = 2;
	return (BOT_NAME);
}
