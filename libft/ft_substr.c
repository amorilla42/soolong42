/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:57:24 by amorilla          #+#    #+#             */
/*   Updated: 2022/05/07 18:59:11 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	leni;
	size_t	i;
	size_t	lentotal;

	if (!s)
		return (0);
	leni = ft_strlen(s);
	if (start > leni)
		lentotal = 0;
	else
		lentotal = ft_min(leni - start, len);
	res = malloc((lentotal + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && i + start < leni)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
