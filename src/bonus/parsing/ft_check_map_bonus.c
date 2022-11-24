/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:33:34 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/15 13:52:13 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

int	ft_check_map(t_var *var)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (var->data.map[i])
	{
		j = 0;
		while (var->data.map[i][j])
		{
			if (ft_strchr("NEWS", var->data.map[i][j]))
				count++;
			ft_check_zeros(var, i, j);
			j++;
		}
		i++;
	}
	if (!count || count > 1)
		ft_print_error("Map not compilant !", var);
	return (1);
}

void	ft_check_zeros(t_var *var, int i, int j)
{
	if (var->data.map[i][j] == '0'
		|| ft_strchr("NEWS", var->data.map[i][j]))
	{
		if (!ft_check_empty(var, i, j))
			ft_print_error("Map not compilant !", var);
	}
}
