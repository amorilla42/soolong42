/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:09:00 by amorilla          #+#    #+#             */
/*   Updated: 2022/05/07 17:43:09 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux)
	{
		aux2 = aux->next;
		del(aux->content);
		free(aux);
		aux = aux2;
	}
	*lst = 0;
}
