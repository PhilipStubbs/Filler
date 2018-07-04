/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placementoutput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 12:09:14 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/04 12:09:15 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	placementoutput(int y, int x)
{
	char *ret;

	ret = ft_strjoin(ft_itoa(y), " ");
	ft_strcat(ret, ft_itoa(x));
	ft_putendl_fd(ret, 1);
	free(ret);
}
