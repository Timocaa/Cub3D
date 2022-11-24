/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:18:57 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/02 15:53:29 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_set_player_position(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->data.map[x])
	{
		y = 0;
		while (var->data.map[x][y])
		{
			if (ft_strchr("NEWS", var->data.map[x][y]))
			{
				ft_set_direction(var, var->data.map[x][y], x, y);
				var->data.map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
}

void	ft_set_direction(t_var *var, char c, double x, double y)
{
	var->play.pos_x = y + 0.5;
	var->play.pos_y = x + 0.5;
	if (c == 'N')
		var->play.dir.y = -1;
	if (c == 'E')
	{
		var->play.dir.x = 1;
		var->plan.x = 0;
		var->plan.y = FOV;
	}
	if (c == 'W')
	{
		var->play.dir.x = -1;
		var->plan.x = 0;
		var->plan.y = -FOV;
	}
	if (c == 'S')
	{
		var->play.dir.y = 1;
		var->plan.x = -FOV;
	}
}
