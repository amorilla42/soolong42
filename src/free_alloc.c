/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:06:23 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 19:20:44 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_and_data_fd(t_data *data, int fd)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
	print_error("Cannot allocate memory");
	close(fd);
	exit(EXIT_FAILURE);
}

void	free_map_and_data(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
	print_error(str);
	exit(EXIT_FAILURE);
}

void	free_copymap(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->copy_map[i]);
		i++;
	}
	free(data->copy_map);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free_img(data);
	mlx_terminate(data->mlx);
	free(data);
}

void	free_data(t_data *data, char *msg)
{
	free(data);
	print_error(msg);
	exit(EXIT_FAILURE);
}
