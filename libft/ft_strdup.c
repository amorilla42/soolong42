/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:56:12 by amorilla          #+#    #+#             */
/*   Updated: 2022/04/27 19:28:59 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		tam;
	char	*str;
	int		i;

	i = 0;
	tam = ft_strlen(s1);
	str = ft_calloc(tam + 1, sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, tam);
	return (str);
}
