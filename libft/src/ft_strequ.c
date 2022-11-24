/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:19:53 by tlafont           #+#    #+#             */
/*   Updated: 2022/04/25 17:48:53 by tlafont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	else
		return (1);
}
