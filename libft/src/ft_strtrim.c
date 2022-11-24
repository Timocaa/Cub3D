/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:16 by fleblanc          #+#    #+#             */
/*   Updated: 2022/09/28 15:21:44 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*cpy;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j && ft_strchr(set, s1[j]) && j > i)
		j--;
	if (s1[i] == '\0')
	{
		cpy = (char *)malloc(1);
		if (cpy == NULL)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	else
		cpy = ft_substr(s1, i, (j - i + 1));
	return (cpy);
}
