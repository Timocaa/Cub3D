/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:08:29 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/22 16:09:01 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 1;
	character = '\0';
	buffer = ft_calloc(sizeof(char), 10000);
	while (rd > 0)
	{
		rd = read(fd, &character, 1);
		buffer[i] = '\0';
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
