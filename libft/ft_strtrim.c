/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:28:29 by amorilla          #+#    #+#             */
/*   Updated: 2022/05/07 19:11:00 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_esta(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	int		contres;

	j = ft_strlen(s1)-1;
	i = 0;
	contres = 0;
	while (ft_esta(s1[i], set) && s1[i] != '\0')
		i++;
	if ((i - 1) == j)
		return (ft_strdup(""));
	while (ft_esta(s1[j], set) && j != 0)
		j--;
	res = malloc(sizeof(char) * (j - i + 2));
	if (!res)
		return (0);
	while (i <= j)
	{
		res[contres] = s1[i];
		i++;
		contres++;
	}
	res[contres] = '\0';
	return (res);
}
