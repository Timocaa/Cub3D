/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturing_fct_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:18:52 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/15 13:50:52 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

void	ft_cpy_texture(int **texture, void *img)
{
	int	bpp;
	int	len_l;
	int	end;
	int	*tmp;
	int	i;

	i = 0;
	tmp = (int *)mlx_get_data_addr(img, &bpp, &len_l, &end);
	*texture = (int *)malloc(sizeof(int) * 4096);
	while (i < 4096)
	{
		(*texture)[i] = tmp[i];
		i++;
	}
}

void	ft_create_floor_ceiling(t_var *var, int color, int start)
{
	int	x;
	int	y;
	int	stop;

	x = 0;
	if (start == 0)
		stop = HEIGHT / 2;
	else
		stop = HEIGHT;
	while (x < stop)
	{
		y = 0;
		while (y < WIDTH)
		{
			ft_pixel_put(var, y, start + x, color);
			y++;
		}
		x++;
	}
}

void	ft_pixel_put(t_var *var, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = var->mlx.addr + (y * var->mlx.line_len + x * (var->mlx.bpp / 8));
		*(unsigned int *)dst = color;
	}
}
