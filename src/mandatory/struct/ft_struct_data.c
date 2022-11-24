/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:28:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/01 11:48:23 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_init_struct_data(t_data *data)
{
	data->north_t = NULL;
	data->south_t = NULL;
	data->west_t = NULL;
	data->east_t = NULL;
	data->floor_c = -1;
	data->ceiling_c = -1;
	data->map = NULL;
	data->map_h = 0;
	data->x = 0;
	data->y = 0;
}

void	ft_free_struc_data(t_data *data)
{
	if (data)
	{
		if (data->north_t)
			free(data->north_t);
		if (data->south_t)
			free(data->south_t);
		if (data->west_t)
			free(data->west_t);
		if (data->east_t)
			free(data->east_t);
		if (data->map)
			ft_free_double_tab((void **)data->map);
	}
}
