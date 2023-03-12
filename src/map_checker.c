/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:40:10 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 17:08:05 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Mapa tiene que estar:
	//-consistente en las medidas (igual de ancho en todas las filas) METER EL ALTO Y ANCHO EN IS RECTANGULAR
	//-Rodeado de muros (1)
	-Que tenga caracteres que NO sean "1, P, E, C"
	-Que tenga inicio (P) y final (E) Y EXCLUSIVAMENTE 1 DE CADA
	-Que tenga al menos 1 coleccionable (C)
	-Que el archivo termine en .ber (las ultimas 4 letras y que sea mas de 5 caracteres)
	-Que puedas recoger todos los coleccionables y llegar al final (A estrella) // cuando sea path al coleccionable, la salida es un muro mas
*/

//check if every row has the same length
static int	map_is_rectangular(t_data *data)
{
	int		i;

	i = 0;
	data->map_width = ft_strlen(data->map[i]);
	i++;
	while (map[i])
	{
		if (size != ft_strlen(data->map[i]))
			return (print_error("Map is not a rectangle"));
		i++;
	}
	data->map_height = i; //mirave si se jode
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

int	is_valid_map(t_data *data)
{
	
}