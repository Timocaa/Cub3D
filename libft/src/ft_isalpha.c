/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:59:12 by tlafont           #+#    #+#             */
/*   Updated: 2022/09/28 15:08:57 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((char)c >= 65 && (char)c <= 90)
		|| ((char)c >= 97 && (char)c <= 122))
		return (1024);
	else
		return (0);
}
