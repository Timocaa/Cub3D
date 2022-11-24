/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:57:09 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/15 13:53:41 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

void	ft_init_ray(t_var *var)
{
	double	cam;

	cam = var->ray.i * 2.0 / (double)WIDTH - 1.0;
	var->ray.dir.x = var->play.dir.x + var->plan.x * cam;
	var->ray.dir.y = var->play.dir.y + var->plan.y * cam;
	var->data.x = (int)var->play.pos_x;
	var->data.y = (int)var->play.pos_y;
	var->ray.delta.x = fabs(1.0 / var->ray.dir.x);
	var->ray.delta.y = fabs(1.0 / var->ray.dir.y);
	var->ray.step_x = 1;
	var->ray.step_y = 1;
	var->ray.len.x = (var->data.x + 1.0 - var->play.pos_x) * var->ray.delta.x;
	var->ray.len.y = (var->data.y + 1.0 - var->play.pos_y) * var->ray.delta.y;
	if (var->ray.dir.y < 0)
	{
		var->ray.step_y = -1;
		var->ray.len.y = (var->play.pos_y - var->data.y) * var->ray.delta.y;
	}
	if (var->ray.dir.x < 0)
	{
		var->ray.step_x = -1;
		var->ray.len.x = (var->play.pos_x - var->data.x) * var->ray.delta.x;
	}
}

void	ft_send_ray(t_var *var)
{
	int	hit;

	hit = 0;
	while (hit != 1)
	{
		if (var->ray.len.x < var->ray.len.y)
		{
			var->ray.len.x += var->ray.delta.x;
			var->data.x += var->ray.step_x;
			var->ray.hit = 0;
		}
		else
		{
			var->ray.len.y += var->ray.delta.y;
			var->data.y += var->ray.step_y;
			var->ray.hit = 1;
		}
		if (var->data.map[var->data.y][var->data.x] == '1')
			hit = 1;
	}
}

void	ft_calcul_wall(t_var *var)
{
	if (var->ray.hit == 0)
		var->wall.dist = var->ray.len.x - var->ray.delta.x;
	else
		var->wall.dist = var->ray.len.y - var->ray.delta.y;
	var->wall.height = (int)(HEIGHT / var->wall.dist);
	var->wall.top = -(var->wall.height / 2) + (HEIGHT / 2);
}

void	ft_find_texture_horizontal(t_var *var)
{
	double	hit_wall;

	if (var->ray.hit == 0)
		hit_wall = var->play.pos_y
			+ var->wall.dist * var->ray.dir.y;
	else
		hit_wall = var->play.pos_x
			+ var->wall.dist * var->ray.dir.x;
	hit_wall -= floor(hit_wall);
	var->wall.texture_x = (int)(hit_wall * NB_PIX);
	if ((var->ray.hit == 0 && var->ray.dir.x > 0)
		|| (var->ray.hit != 0 && var->ray.dir.y < 0))
	{
		var->wall.texture_x = NB_PIX - var->wall.texture_x - 1;
	}
}
