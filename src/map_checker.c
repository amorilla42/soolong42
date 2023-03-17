/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:40:10 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 11:43:14 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	Mapa tiene que estar:
	//-consistente en las medidas (igual de ancho en todas las filas) METER EL ALTO Y ANCHO EN IS RECTANGULAR
	//-Rodeado de muros (1)
	//-Que tenga caracteres que NO sean "1, P, E, C"
	//-Que tenga inicio (P) y final (E) Y EXCLUSIVAMENTE 1 DE CADA
	//-Que tenga al menos 1 coleccionable (C)
	//-Que el archivo termine en .ber (las ultimas 4 letras y que sea mas de 5 caracteres)
	-Que puedas recoger todos los coleccionables y llegar al final (A estrella) // cuando sea path al coleccionable, la salida es un muro mas
*/

//check if every row has the same length
static int	map_is_rectangular(t_data *data)
{
	int		i;
	int		row_len;

	i = 0;
	data->map_width = ft_strlen(data->map[i]) - 1;
	i++;
	while (data->map[i])
	{
		row_len = (int)(ft_strlen(data->map[i]) - 1);
		if (i == data->map_height - 1)
			row_len++;
		if (data->map_width != row_len)
			return (print_error("Map is not a rectangle"));
		i++;
	}
	return (1);
}

static int	map_has_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (map[i][j])
	{
		if ((map[i][j - 1] != '1') || (map[ft_strlen(map[i]) - 2][j - 1] != '1'))
			return (print_error("Map is not surrounded by walls usted"));
		j++;
	}
	i++;
	while (i < ft_strlen(map[i]) - 1)
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[i]) - 2] != '1'))
			return (print_error("Map is not surrounded by walls"));
		i++;
	}
	return (1);
}

int	is_valid_map(t_data *data)
{
	//if es true la funcion de hacer pathfinding con cada gusano y despues con la salida AQUI
	return (map_has_walls(data->map)
		&& map_is_rectangular(data) && map_inner_check(data));
}
