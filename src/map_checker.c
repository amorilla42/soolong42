/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:40:10 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 15:39:47 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Mapa tiene que estar:
	//-consistente en las medidas (igual de ancho en todas las filas)
	//-Rodeado de muros (1)
	-Que tenga caracteres que NO sean "1, P, E, C"
	-Que tenga inicio (P) y final (E) Y EXCLUSIVAMENTE 1 DE CADA
	-Que tenga al menos 1 coleccionable (C)
	-Que el archivo termine en .ber (las ultimas 4 letras y que sea mas de 5 caracteres)
	-Que puedas recoger todos los coleccionables y llegar al final (A estrella)
*/

//check if every row has the same length
static int	map_is_rectangular(char **map)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		if (size != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	map_has_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if ((map[i][j] != 1) || (map[ft_strlen(map) - 1][j] != 1))
			return (print_error("Map is not surrounded by walls"));
		j++;
	}
	i++;
	while (i < ft_strlen(map) - 1)
	{
		if ((map[i][0] != 1) || (map[i][ft_strlen(map) - 1] != 1))
			return (print_error("Map is not surrounded by walls"));
		i++;
	}
	return (1);
}

int	map_inner_check(char **map)
{
	int	num_p;
	int	num_e;
	int	num_c;
	int	i;
	int	j;
	
	num_c = 0;
	i = 0;
	j = 0;
	num_e = 0;
}

int	is_valid_map(t_data *data)
{
	
}