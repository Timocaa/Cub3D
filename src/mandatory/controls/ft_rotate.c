/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:32:28 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/15 10:08:15 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	ft_rotate_left(t_var *var)
{
	double	x;
	double	y;
	double	plan_x;
	double	plan_y;

	x = var->play.dir.x;
	y = var->play.dir.y;
	plan_x = var->plan.x;
	plan_y = var->plan.y;
	var->play.dir.x = x * cos(-DEG_TO_RAD * SPEED_R)
		- y * sin(-DEG_TO_RAD * SPEED_R);
	var->play.dir.y = x * sin(-DEG_TO_RAD * SPEED_R)
		+ y * cos(-DEG_TO_RAD * SPEED_R);
	var->plan.x = plan_x * cos(-DEG_TO_RAD * SPEED_R)
		- plan_y * sin(-DEG_TO_RAD * SPEED_R);
	var->plan.y = plan_x * sin(-DEG_TO_RAD * SPEED_R)
		+ plan_y * cos(-DEG_TO_RAD * SPEED_R);
	ft_draw_screen(var);
}

void	ft_rotate_right(t_var *var)
{
	double	x;
	double	y;
	double	plan_x;
	double	plan_y;

	x = var->play.dir.x;
	y = var->play.dir.y;
	plan_x = var->plan.x;
	plan_y = var->plan.y;
	var->play.dir.x = x * cos(DEG_TO_RAD * SPEED_R)
		- y * sin(DEG_TO_RAD * SPEED_R);
	var->play.dir.y = x * sin(DEG_TO_RAD * SPEED_R)
		+ y * cos(DEG_TO_RAD * SPEED_R);
	var->plan.x = plan_x * cos(DEG_TO_RAD * SPEED_R)
		- plan_y * sin(DEG_TO_RAD * SPEED_R);
	var->plan.y = plan_x * sin(DEG_TO_RAD * SPEED_R)
		+ plan_y * cos(DEG_TO_RAD * SPEED_R);
	ft_draw_screen(var);
}
