/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:59 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/15 13:44:15 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>
# include <X11/keysym.h>

# define WIDTH 1280
# define HEIGHT 720
# define FOV 0.66
# define NB_PIX 64
# define SPEED_M 0.2 
# define SPEED_R 10
# define DEG_TO_RAD 0.0174533

typedef struct s_data	t_data;
typedef struct s_var	t_var;
typedef struct s_mlx	t_mlx;
typedef struct s_play	t_play;
typedef struct s_coord	t_coord;
typedef struct s_ray	t_ray;
typedef struct s_wall	t_wall;

struct s_wall
{
	int		height;
	int		top;
	int		texture_x;
	double	texture_y;
	int		width;
	double	dist;
};

struct s_coord
{
	double	x;
	double	y;
};

struct s_ray
{
	int		i;
	t_coord	dir;
	t_coord	delta;
	t_coord	len;
	int		step_x;
	int		step_y;
	int		hit;
};

struct s_play
{
	t_coord	dir;
	double	pos_x;
	double	pos_y;
};

struct s_data
{
	int		*north_t;
	int		*south_t;
	int		*west_t;
	int		*east_t;
	int		floor_c;
	int		ceiling_c;
	char	**map;
	int		map_h;
	int		x;
	int		y;
};

struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		end;
};

struct s_var
{
	t_coord	plan;
	t_play	play;
	t_data	data;
	t_mlx	mlx;
	t_ray	ray;
	t_wall	wall;
};

//parsing ---------------------------------------------------------------------
		//parsing_line --------------------------------------------------------
int		ft_parsing_line(t_var *var, char *line);
int		ft_parsing_texture(t_var *var, int **texture, char *line);
int		ft_parsing_color(t_var *var, int *trgb, char *line);
int		ft_parsing_map_line(t_var *var, char *line);
int		ft_check_map_line(char *line);
		//check_file ----------------------------------------------------------
void	ft_check_file(t_var *var, char *file_name);
int		ft_check_extension(char *file_name);
int		ft_check_texture_file(char *file_name);
int		ft_check_empty(t_var *var, int i, int j);
		//check_map -----------------------------------------------------------
int		ft_check_map(t_var *var);
void	ft_check_zeros(t_var *var, int i, int j);

//init ------------------------------------------------------------------------
		//init_draw -----------------------------------------------------------
void	ft_set_player_position(t_var *var);
void	ft_set_direction(t_var *var, char c, double x, double y);

//struct ----------------------------------------------------------------------
		//struct_var ----------------------------------------------------------
void	ft_init_var(t_var *var);
void	ft_free_var(t_var *var);

		//struct_data ---------------------------------------------------------
void	ft_init_struct_data(t_data *data);
void	ft_free_struc_data(t_data *data);

		//struct_mlx ----------------------------------------------------------
void	ft_init_var_mlx(t_mlx *mlx);
void	ft_init_struct_mlx(t_var *var);
void	ft_free_mlx(t_mlx *mlx);

		//struct_play ---------------------------------------------------------
void	ft_init_struct_play(t_play *play);

		//struct_ray ----------------------------------------------------------
void	ft_init_struct_ray(t_ray *ray);

		//struct_wall ---------------------------------------------------------
void	ft_init_struct_wall(t_wall *wall);

//raycasting ------------------------------------------------------------------
		//minimap -------------------------------------------------------------
void	ft_draw_minimap(t_var *var);
void	ft_display_map_point(t_var *var, int color, int x, int y);
void	ft_draw_mini_fov(t_var *var);

void	ft_display_map_point(t_var *var, int color, int x, int y);
		//draw_screen ---------------------------------------------------------
void	ft_draw_screen(t_var *var);
void	ft_draw_vertical_line(t_var *var);
int		ft_recover_img_color(t_var *var);

		//rc_init -------------------------------------------------------------
void	ft_init_ray(t_var *var);
void	ft_send_ray(t_var *var);
void	ft_calcul_wall(t_var *var);
void	ft_find_texture_horizontal(t_var *var);

//image -----------------------------------------------------------------------
		//texturing_fct -------------------------------------------------------
void	ft_cpy_texture(int **texture, void *img);
void	ft_create_floor_ceiling(t_var *var, int color, int start);
void	ft_pixel_put(t_var *var, int x, int y, int color);

		//color_fct -----------------------------------------------------------
int		ft_color_recovery(char *line, int *rgb);
int		ft_next_data_color(char *line, int i);
//close -----------------------------------------------------------------------
		//error ---------------------------------------------------------------
void	ft_print_error(char *msg, t_var *var);

		//close ---------------------------------------------------------------
int		ft_close(t_var *var);

//controls --------------------------------------------------------------------
		//moves ---------------------------------------------------------------
int		ft_move_player(int keycode, t_var *var);
void	ft_move_up(t_var *var);
void	ft_move_down(t_var *var);
void	ft_move_left(t_var *var);
void	ft_move_right(t_var *var);

		// rotate -------------------------------------------------------------
void	ft_rotate_left(t_var *var);
void	ft_rotate_right(t_var *var);

#endif
