/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:40:10 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 19:15:51 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	map_has_walls(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map[i][j])
	{
		if ((map[i][j - 1] != '1') || (map[data->map_height - 1][j - 1] != '1'))
			return (print_error("Map is not surrounded by walls usted"));
		j++;
	}
	i++;
	while (i < data->map_height)
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[i]) - 2] != '1'))
			return (print_error("Map is not surrounded by walls"));
		i++;
	}
	return (1);
}

int	is_valid_map(t_data *data)
{
	return (map_is_rectangular(data)
		&& map_has_walls(data, data->map) && map_inner_check(data)
		&& map_path_check(data));
}
