/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:15:41 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/21 13:35:40 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

int	ft_move_player(int keycode, t_var *var)
{
	if (keycode == XK_w)
		ft_move_up(var);
	else if (keycode == XK_s)
		ft_move_down(var);
	else if (keycode == XK_a)
		ft_move_left(var);
	else if (keycode == XK_d)
		ft_move_right(var);
	else if (keycode == XK_Right)
		ft_rotate_right(var);
	else if (keycode == XK_Left)
		ft_rotate_left(var);
	else if (keycode == XK_Escape)
		ft_close(var);
	return (0);
}

void	ft_move_up(t_var *var)
{
	if (var->data.map[(int)(var->play.pos_y - 0.3)]
		[(int)(var->play.pos_x + var->play.dir.x * SPEED_M)] == '0')
		var->play.pos_x += var->play.dir.x * SPEED_M;
	if (var->play.pos_x >= ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3)
		var->play.pos_x = ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3;
	if (var->data.map[(int)(var->play.pos_y + var->play.dir.x * SPEED_M - 0.3)]
		[(int)var->play.pos_x] == '0')
		var->play.pos_y += var->play.dir.y * SPEED_M;
	if (var->play.pos_y < 1.3)
		var->play.pos_y = 1.3;
	ft_draw_screen(var);
}

void	ft_move_down(t_var *var)
{
	if (var->data.map[(int)(var->play.pos_y + 0.3)]
		[(int)(var->play.pos_x - var->play.dir.x * SPEED_M)] == '0')
		var->play.pos_x -= var->play.dir.x * SPEED_M;
	if (var->play.pos_x >= ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3)
		var->play.pos_x = ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3;
	if (var->data.map[(int)(var->play.pos_y - var->play.dir.x * SPEED_M + 0.3)]
		[(int)var->play.pos_x] == '0')
		var->play.pos_y -= var->play.dir.y * SPEED_M;
	if (var->play.pos_y < 1.3)
		var->play.pos_y = 1.3;
	ft_draw_screen(var);
}

void	ft_move_right(t_var *var)
{
	if (var->data.map[(int)var->play.pos_y]
		[(int)(var->play.pos_x + var->plan.x * SPEED_M + 0.3)] == '0')
		var->play.pos_x += var->plan.x * SPEED_M;
	if (var->play.pos_x >= ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3)
		var->play.pos_x = ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3;
	if (var->data.map[(int)(var->play.pos_y + var->plan.y * SPEED_M)]
		[(int)(var->play.pos_x + 0.3)] == '0')
		var->play.pos_y += var->plan.y * SPEED_M;
	if (var->play.pos_y < 1.3)
		var->play.pos_y = 1.3;
	ft_draw_screen(var);
}

void	ft_move_left(t_var *var)
{
	if (var->data.map[(int)var->play.pos_y]
		[(int)(var->play.pos_x - var->plan.x * SPEED_M - 0.3)] == '0')
		var->play.pos_x -= var->plan.x * SPEED_M;
	if (var->play.pos_x >= ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3)
		var->play.pos_x = ft_strlen(var->data.map[(int)(var->play.pos_y - 0.3)]) - 1.3;
	if (var->data.map[(int)(var->play.pos_y - var->plan.y * SPEED_M)]
		[(int)(var->play.pos_x - 0.3)] == '0')
		var->play.pos_y -= var->plan.y * SPEED_M;
	if (var->play.pos_y < 1.3)
		var->play.pos_y = 1.3;
	ft_draw_screen(var);
}
