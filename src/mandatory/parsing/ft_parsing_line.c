/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:10:55 by tlafont           #+#    #+#             */
/*   Updated: 2022/11/05 15:26:06 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	ft_parsing_line(t_var *var, char *line)
{
	int	i;
	int	value;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n' && !var->data.map)
		return (1);
	else if (line[i] == '1')
		value = ft_parsing_map_line(var, line);
	else if (!ft_strncmp(&line[i], "NO ", 3))
		value = ft_parsing_texture(var, &(var)->data.north_t, &line[i + 3]);
	else if (!ft_strncmp(&line[i], "SO ", 3))
		value = ft_parsing_texture(var, &(var)->data.south_t, &line[i + 3]);
	else if (!ft_strncmp(&line[i], "WE ", 3))
		value = ft_parsing_texture(var, &(var)->data.west_t, &line[i + 3]);
	else if (!ft_strncmp(&line[i], "EA ", 3))
		value = ft_parsing_texture(var, &(var)->data.east_t, &line[i + 3]);
	else if (!ft_strncmp(&line[i], "F ", 2))
		value = ft_parsing_color(var, &(var)->data.floor_c, &line[i + 2]);
	else if (!ft_strncmp(&line[i], "C ", 2))
		value = ft_parsing_color(var, &(var)->data.ceiling_c, &line[i + 2]);
	else
		return (0);
	return (value);
}

int	ft_parsing_texture(t_var *var, int **texture, char *line)
{
	int		i;
	void	*tmp;
	int		pix[2];

	i = 0;
	if (var->data.map || *texture)
		return (0);
	while (*line && ft_isspace(*line))
		line++;
	i = ft_strlen(line) - 1;
	while (i > 0 && ft_isspace(line[i]))
		i--;
	line[i + 1] = '\0';
	if (!ft_check_texture_file(line))
		return (0);
	tmp = mlx_xpm_file_to_image(var->mlx.mlx, line, &pix[0], &pix[1]);
	if (pix[0] != 64 || pix[1] != 64 || !tmp)
	{
		if (tmp)
			mlx_destroy_image(var->mlx.mlx, tmp);
		return (0);
	}
	ft_cpy_texture(texture, tmp);
	mlx_destroy_image(var->mlx.mlx, tmp);
	return (1);
}

int	ft_parsing_color(t_var *var, int *trgb, char *line)
{
	int	rgb[3];
	int	i;

	i = 0;
	if (var->data.map || *trgb != -1)
		return (0);
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			if (!ft_isspace(line[i]) && line[i] != '+' && line[i] != ',')
				return (0);
		}
		i++;
	}
	i = ft_color_recovery(line, rgb);
	if (line[i] != '\0' || rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (0);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (0);
	*trgb = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	return (1);
}

int	ft_parsing_map_line(t_var *var, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!var->data.north_t || !var->data.south_t || !var->data.east_t
		|| !var->data.west_t || var->data.floor_c == -1
		|| var->data.ceiling_c == -1)
		return (0);
	if (!ft_check_map_line(line))
		return (0);
	var->data.map_h++;
	tmp = (char **)malloc(sizeof(char *) * (var->data.map_h + 1));
	if (!tmp)
		ft_print_error("alloc parsing map line failed !", var);
	while (i < var->data.map_h - 1)
	{
		tmp[i] = ft_strdup(var->data.map[i]);
		i++;
	}
	tmp[i] = ft_strndup(line, ft_strlen(line) - 1);
	tmp[i + 1] = NULL;
	if (var->data.map_h > 1)
		ft_free_double_tab((void **)var->data.map);
	var->data.map = tmp;
	return (1);
}

int	ft_check_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != 'S'
			&& !ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}
