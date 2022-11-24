/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:28:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/04 10:34:01 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

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
