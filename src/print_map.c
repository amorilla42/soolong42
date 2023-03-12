/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:27:33 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 16:36:39 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

print_map(t_data *data, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		while (j < data->map_width)
		{
			mlx_image_to_window(data->mlx, data->floor, j*size, i*size)
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->fence, j*size, i*size);
			else if (data->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->food, j*size, i*size);
			else if (data->map[i][j] == 'P')
				mlx_image_to_window(data->mlx, data->player, j*size, i*size);
			else if (data->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->exit, j*size, i*size);
			j++;
		}
		i++;
	}
}