/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:28:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/15 10:14:04 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_init_struct_wall(t_wall *wall)
{
	wall->height = NB_PIX;
	wall->top = 0;
	wall->texture_x = 0;
	wall->texture_y = 0;
	wall->width = 0;
	wall->dist = 0;
}
