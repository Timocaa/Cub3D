/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:28:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/01 10:37:58 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_init_struct_play(t_play *play)
{
	play->pos_x = 0;
	play->pos_y = 0;
	play->dir.x = 0;
	play->dir.y = 0;
}
