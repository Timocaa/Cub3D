/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:42:59 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:46:13 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	int		cmp;

	str1 = (char *)malloc(sizeof(str1) * (ft_strlen(s1) + 1));
	str2 = (char *)malloc(sizeof(str2) * (ft_strlen(s2) + 1));
	if (str1 == NULL || str2 == NULL)
		return (0);
	ft_strcpy(str1, s1);
	ft_strcpy(str2, s2);
	ft_strlowcase(str1);
	ft_strlowcase(str2);
	cmp = ft_strcmp(str1, str2);
	free(str1);
	free(str2);
	return (cmp);
}
