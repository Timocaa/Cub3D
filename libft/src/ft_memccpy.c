/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:58:09 by tlafont           #+#    #+#             */
/*   Updated: 2022/09/28 15:24:56 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	int				i;

	if (!dest && !src)
		return (dest);
	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (n--)
	{
		dest2[i] = src2[i];
		if (dest2[i] == (unsigned char)c)
			return ((&dest2[i]) + 1);
		i++;
	}
	return (NULL);
}
