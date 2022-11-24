/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:15:36 by fleblanc          #+#    #+#             */
/*   Updated: 2022/11/15 13:51:59 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d_bonus.h"

void	ft_check_file(t_var *var, char *file_name)
{
	int		fd;
	char	*line;
	int		value;

	if (!ft_check_extension(file_name))
		ft_print_error("Extension not compilant !", var);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_print_error("Can't open file !", var);
	ft_init_struct_mlx(var);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		value = ft_parsing_line(var, line);
		if (line)
			free(line);
		if (!value)
		{
			close(fd);
			ft_print_error("Invalid map file !", var);
		}
	}
	close(fd);
}

int	ft_check_extension(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	while (i >= 0 && file_name[i] != '/')
		i--;
	if (ft_strncmp(&file_name[i + 1], ".cub", 4) != 0)
	{
		if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".cub") == 0)
			return (1);
	}
	return (0);
}

int	ft_check_texture_file(char *file_name)
{
	int	i;
	int	fd;

	if (!file_name)
		return (0);
	i = ft_strlen(file_name);
	if (ft_strncmp(&file_name[i - 4], ".xpm", 4))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	ft_check_empty(t_var *var, int i, int j)
{
	if (!i || !var->data.map[i][j])
		return (0);
	if (!j || !var->data.map[i + 1])
		return (0);
	if (var->data.map[i - 1][j] == ' ' || !var->data.map[i - 1][j])
		return (0);
	if (var->data.map[i - 1][j + 1] == ' ' || !var->data.map[i - 1][j + 1])
		return (0);
	if (var->data.map[i - 1][j - 1] == ' ' || !var->data.map[i - 1][j - 1])
		return (0);
	if (var->data.map[i + 1][j] == ' ' || !var->data.map[i + 1][j])
		return (0);
	if (var->data.map[i + 1][j + 1] == ' ' || !var->data.map[i + 1][j + 1])
		return (0);
	if (var->data.map[i + 1][j - 1] == ' ' || !var->data.map[i + 1][j - 1])
		return (0);
	if (var->data.map[i][j - 1] == ' ' || !var->data.map[i][j - 1])
		return (0);
	if (var->data.map[i][j + 1] == ' ' || !var->data.map[i][j + 1])
		return (0);
	return (1);
}
