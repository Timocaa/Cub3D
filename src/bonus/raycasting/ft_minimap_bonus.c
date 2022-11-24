/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:31:31 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/15 13:53:31 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

void	ft_draw_minimap(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->data.map[x])
	{
		y = 0;
		while (var->data.map[x][y])
		{
			if (var->data.map[x][y] == '0')
				ft_display_map_point(var, 0x000000, y * 10, x * 10);
			if (var->data.map[x][y] == '1')
				ft_display_map_point(var, 0xffffff, y * 10, x * 10);
			y++;
		}
		x++;
	}
	ft_display_map_point(var, 0xff0000, (int)var->play.pos_x * 10,
		(int)var->play.pos_y * 10);
}

void	ft_display_map_point(t_var *var, int color, int x, int y)
{
	int	x_init;
	int	y_init;

	y_init = y;
	while (y_init < 10 + y)
	{
		x_init = x;
		while (x_init < 10 + x)
		{
			ft_pixel_put(var, x_init, y_init, color);
			x_init++;
		}
		y_init++;
	}
}
