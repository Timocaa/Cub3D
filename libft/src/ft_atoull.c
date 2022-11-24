/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:30:58 by fleblanc          #+#    #+#             */
/*   Updated: 2022/09/28 15:07:41 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_atoull(const char *nptr)
{
	int					i;
	unsigned long long	nb;

	i = 0;
	nb = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
	}
	return (nb);
}
