/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:01:28 by amorilla          #+#    #+#             */
/*   Updated: 2022/04/27 19:42:13 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	int		mult;

	mult = count * size;
	if ((count != 0) && ((mult / count) != size))
		return (0);
	mem = malloc(mult);
	if (!mem)
		return (0);
	ft_bzero(mem, mult);
	return (mem);
}
