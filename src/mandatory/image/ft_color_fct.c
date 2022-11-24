/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:49:40 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/21 11:04:59 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	ft_color_recovery(char *line, int *rgb)
{
	int	i;

	i = 0;
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	if (line [i] == '\0' || line[i] == ',')
		return (i);
	rgb[0] = ft_atoi(line);
	i = ft_next_data_color(line, i);
	i++;
	if (line [i] == '\0' || line[i] == ',')
		return (i);
	rgb[1] = ft_atoi(&line[i]);
	i = ft_next_data_color(line, i);
	i++;
	if (line [i] == '\0' || line[i] == ',')
		return (i);
	rgb[2] = ft_atoi(&line[i]);
	i = ft_next_data_color(line, i);
	return (i);
}

int	ft_next_data_color(char *line, int i)
{
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '+')
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}
