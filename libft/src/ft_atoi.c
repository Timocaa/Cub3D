/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:34:27 by tlafont           #+#    #+#             */
/*   Updated: 2022/09/28 15:07:24 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ') && nptr[i])
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
	{
		nb *= 10;
		nb += (nptr[i] - 48);
		i++;
	}
	return ((int)nb * sign);
}
