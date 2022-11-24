/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:05:09 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/15 13:58:34 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_var	var;
	int		chk;

	chk = 0;
	if (argc == 2)
	{
		ft_init_var(&var);
		ft_check_file(&var, argv[1]);
		chk = ft_check_map(&var);
		ft_set_player_position(&var);
		if (chk)
		{
			ft_draw_screen(&var);
			mlx_hook(var.mlx.mlx_win, 2, 1L << 0, ft_move_player, &var);
			mlx_hook(var.mlx.mlx_win, DestroyNotify, 0, ft_close, &var);
			mlx_loop(var.mlx.mlx);
		}
	}
	else
		ft_print_error("Program only need 1 argument.", NULL);
	return (0);
}
