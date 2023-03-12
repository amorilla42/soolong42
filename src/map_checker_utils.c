/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:09:52 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 21:04:04 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	value_is_valid(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
		data->num_food++;
	else if (data->map[i][j] == 'P')
	{
		data->num_players++;
		data->pos_player_x = i;//posibles problemos
		data->pos_player_y = j;
	}
	else if (data->map[i][j] == 'E')
		data->num_exit++;
	else if ((data->map[i][j] != '1') && (data->map[i][j] != '\n')
		&& (data->map[i][j] != '0'))
		return (0);
	return (1);
}

int	map_inner_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		while (j < data->map_width)
		{
			if (!value_is_valid(data, i, j))
				free_map_and_data(data, "Invalid char in map");
			j++;
		}
		i++;
	}
	if (data->num_food < 1 || data->num_players != 1 || data->num_exit != 1)
		free_map_and_data(data,
			"There is more than one E or P, or less than one C in map");
	return (1);
}
