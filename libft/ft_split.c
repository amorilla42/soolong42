/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:27:15 by amorilla          #+#    #+#             */
/*   Updated: 2022/05/07 19:15:00 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(const char *txt, char c)
{	
	int	numpal;
	int	i;
	int	anteriorsep;

	numpal = 0;
	anteriorsep = 0;
	i = 0;
	while (txt[i] != '\0')
	{
		if ((txt[i] != c) && (anteriorsep == 0))
		{
			anteriorsep = 1;
			numpal++;
		}
		else if (txt[i] == c)
			anteriorsep = 0;
		i++;
	}
	return (numpal);
}

static char	*allocpalabra(const char *s, int inicio, int final)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(sizeof(char) * (final - inicio + 1));
	while (inicio < final)
	{
		str[i] = s[inicio];
		i++;
		inicio++;
	}
	str[i] = '\0';
	return (str);
}

static int	initialize(char ***strstr, const char *s, char c, size_t *j)
{
	*j = 0;
	if (!s)
		return (0);
	*strstr = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!*strstr)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strstr;
	size_t	i;
	size_t	j;
	int		idxseparador;

	i = 0;
	if (!initialize(&strstr, s, c, &j))
		return (0);
	idxseparador = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && idxseparador < 0)
			idxseparador = i;
		else if ((s[i] == c || i == ft_strlen(s)) && idxseparador >= 0)
		{
			strstr[j] = allocpalabra(s, idxseparador, i);
			idxseparador = -1;
			j++;
		}
		i++;
	}
	strstr[j] = 0;
	return (strstr);
}
