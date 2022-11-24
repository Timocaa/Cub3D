/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlafont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:28:29 by tlafont           #+#    #+#             */
/*   Updated: 2022/08/11 14:01:01 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*tmp;

	if (lst == NULL)
		return ;
	elem = *lst;
	while (elem != NULL)
	{
		tmp = elem->next;
		ft_lstdelone(elem, (*del));
		elem = tmp;
	}
	*lst = NULL;
}
