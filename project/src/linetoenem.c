/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linetoenem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 09:25:20 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/03 09:25:21 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		linetoenem(t_phill *node)
{
	int		myx;
	int		myy;
	char	**myxy;
	char	**txy;

	myxy = ft_split(findstart(node, node->piece), ' ');
	txy = ft_split(findstart(node, node->enem), ' ');
	myx = ft_atoi(myxy[0]);
	myy = ft_atoi(myxy[1]);
	if (node->player == 1)
		lineplayerone(node, myy, myx, txy);
	else if (node->player == 2)
		lineplayertwo(node, myy, myx, myxy);
	return (1);
}
