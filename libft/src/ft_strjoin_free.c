/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:32:59 by tlafont           #+#    #+#             */
/*   Updated: 2022/09/28 15:17:33 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(*join) * (len + 1));
	if (join == NULL)
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	free((char *)s1);
	return (join);
}
