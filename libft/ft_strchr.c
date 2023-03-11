/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:34:10 by amorilla          #+#    #+#             */
/*   Updated: 2022/04/23 15:19:32 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	esta;

	esta = 0;
	while (*s != '\0' && !esta)
	{
		if (*s == (char)c)
			esta = 1;
		if (!esta)
			s++;
	}
	if (esta || (*s == '\0' && *s == (char)c))
		return ((char *)s);
	return (0);
}
