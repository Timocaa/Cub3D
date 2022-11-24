/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:29:40 by tlafont           #+#    #+#             */
/*   Updated: 2022/10/05 10:30:32 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_str_is_alnum(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}
