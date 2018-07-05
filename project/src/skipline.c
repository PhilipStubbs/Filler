/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:53:29 by pstubbs           #+#    #+#             */
/*   Updated: 2018/06/15 11:53:32 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		skipline(int fd)
{
	int		i;
	char	*buff;

	buff = (char*)malloc(1 + 1);
	while ((i = read(fd, buff, 1)) > 0)
	{
		if (ft_strchr(buff, '\n'))
		{
			break ;
		}
	}
	ft_bzero(buff, 2);
	return (1);
}
