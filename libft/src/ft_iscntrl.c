/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:15:42 by tlafont           #+#    #+#             */
/*   Updated: 2022/09/28 15:09:24 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iscntrl(int c)
{
	if (((char)c >= 0 && (char)c <= 31) || (char)c == 127)
		return (2);
	else
		return (0);
}
