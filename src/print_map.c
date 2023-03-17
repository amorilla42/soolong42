/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:27:33 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 11:36:00 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_data *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			mlx_image_to_window(data->mlx, data->floor, j * size, i * size);
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->fence, j * size, i * size);
			else if (data->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->food, j * size, i * size);
			else if (data->map[i][j] == 'P')
				mlx_image_to_window(data->mlx, data->player, j * size,
					i * size);
			else if (data->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->exit, j * size, i * size);
			j++;
		}
		i++;
	}
}

int	check_exit(t_data *data, char next_pos)
{
	if (data->num_food == 0 && next_pos == 'E')
	{
		free_all(data);
		ft_putendl_fd("You Won", 1);
		exit(EXIT_SUCCESS);
	}
	else if (data->num_food != 0 && next_pos == 'E')
	{
		ft_putendl_fd("There are more Worms to eat!!", 1);
		return (1);
	}
	return (0);
}
