/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:46:07 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/15 10:04:10 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_init_var(t_var *var)
{
	ft_init_struct_data(&(var)->data);
	ft_init_var_mlx(&(var)->mlx);
	var->plan.x = FOV;
	var->plan.y = 0;
	ft_init_struct_play(&(var)->play);
	ft_init_struct_ray(&(var)->ray);
	ft_init_struct_wall(&(var)->wall);
}

void	ft_free_var(t_var *var)
{
	if (var)
	{
		ft_free_struc_data(&(var)->data);
		ft_free_mlx(&(var)->mlx);
		exit(0);
	}
}
