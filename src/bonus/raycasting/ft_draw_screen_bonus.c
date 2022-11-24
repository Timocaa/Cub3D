/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_screen_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:05:06 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/21 13:40:46 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

void	ft_draw_screen(t_var *var)
{
	var->ray.i = 0;
	ft_create_floor_ceiling(var, var->data.ceiling_c, 0);
	ft_create_floor_ceiling(var, var->data.floor_c, HEIGHT / 2);
	while (var->ray.i < WIDTH)
	{
		ft_init_ray(var);
		ft_send_ray(var);
		ft_calcul_wall(var);
		ft_find_texture_horizontal(var);
		ft_draw_vertical_line(var);
		var->ray.i++;
	}
	ft_draw_minimap(var);
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.mlx_win, var->mlx.img, 0, 0);
}

void	ft_draw_vertical_line(t_var *var)
{
	double	offset;
	int		i;
	int		color;

	i = 0;
	offset = (double)NB_PIX / (double)var->wall.height;
	var->wall.texture_y = 0;
	while (i <= var->wall.height)
	{
		color = ft_recover_img_color(var);
		ft_pixel_put(var, var->ray.i, var->wall.top + i, color);
		var->wall.texture_y += offset;
		i++;
	}
}

int	ft_recover_img_color(t_var *var)
{
	int	*texture;

	if (var->ray.hit == 0)
	{
		if (var->ray.dir.x < 0)
			texture = var->data.east_t;
		else
			texture = var->data.west_t;
	}
	else
	{
		if (var->ray.dir.y < 0)
			texture = var->data.south_t;
		else
			texture = var->data.north_t;
	}
	if (var->wall.texture_y >= 64.0)
		var->wall.texture_y = 63.9;
	return (texture[NB_PIX * (int)floor(var->wall.texture_y)
			+ var->wall.texture_x]);
}
