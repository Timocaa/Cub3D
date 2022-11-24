/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ray_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:28:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/15 13:56:28 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

void	ft_init_struct_ray(t_ray *ray)
{
	ray->i = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->delta.x = 0;
	ray->delta.y = 0;
	ray->len.x = 0;
	ray->len.y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
}
