/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:28:22 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/15 15:57:48 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_init_var_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->mlx_win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->line_len = 0;
	mlx->end = 0;
}

void	ft_init_struct_mlx(t_var *var)
{
	var->mlx.mlx = mlx_init();
	if (!var->mlx.mlx)
		ft_print_error("Allocation mlx failed !", var);
	var->mlx.mlx_win = mlx_new_window(var->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!var->mlx.mlx_win)
		ft_print_error("Window creation failed !", var);
	var->mlx.img = mlx_new_image(var->mlx.mlx, WIDTH, HEIGHT);
	if (!var->mlx.img)
		ft_print_error("Image creation failed !", var);
	var->mlx.addr = mlx_get_data_addr(var->mlx.img, &(var)->mlx.bpp,
			&(var)->mlx.line_len, &(var)->mlx.end);
	if (!var->mlx.addr)
		ft_print_error("Recovery addr_img failed !", var);
}

void	ft_free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->mlx && mlx->mlx_win)
			mlx_clear_window(mlx->mlx, mlx->mlx_win);
		if (mlx->img)
			mlx_destroy_image(mlx->mlx, mlx->img);
		if (mlx->mlx_win)
			mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		if (mlx->mlx)
			mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}
