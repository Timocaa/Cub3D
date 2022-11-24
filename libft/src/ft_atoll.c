/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:42:13 by tlafont           #+#    #+#             */
/*   Updated: 2022/09/28 15:07:35 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoll(const char *nptr)
{
	int				i;
	long long int	nb;
	int				sign;

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
	return (nb * sign);
}
