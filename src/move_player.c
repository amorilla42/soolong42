/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:43:14 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 11:48:09 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_data *data)
{
	if ((data->map[data->pos_player_x][data->pos_player_y - 1] != '1')
		&& !check_exit(data,
		data->map[data->pos_player_x][data->pos_player_y - 1]))
	{
		data->num_movements++;
		if (data->map[data->pos_player_x][data->pos_player_y - 1] == 'C')
			data->num_food--;
		data->map[data->pos_player_x][data->pos_player_y - 1] = 'P';
		data->map[data->pos_player_x][data->pos_player_y] = '0';
		data->pos_player_y--;
		ft_putnbr_fd(data->num_movements, 1);
		ft_putchar_fd('\n', 1);
		print_map(data, 32);
	}
}

static void	move_right(t_data *data)
{
	if ((data->map[data->pos_player_x][data->pos_player_y + 1] != '1')
		&& !check_exit(data,
		data->map[data->pos_player_x][data->pos_player_y + 1]))
	{
		data->num_movements++;
		if (data->map[data->pos_player_x][data->pos_player_y + 1] == 'C')
			data->num_food--;
		data->map[data->pos_player_x][data->pos_player_y + 1] = 'P';
		data->map[data->pos_player_x][data->pos_player_y] = '0';
		data->pos_player_y++;
		ft_putnbr_fd(data->num_movements, 1);
		ft_putchar_fd('\n', 1);
		print_map(data, 32);
	}
}

static void	move_up(t_data *data)
{
	if ((data->map[data->pos_player_x - 1][data->pos_player_y] != '1')
		&& !check_exit(data,
		data->map[data->pos_player_x - 1][data->pos_player_y]))
	{
		data->num_movements++;
		if (data->map[data->pos_player_x - 1][data->pos_player_y] == 'C')
			data->num_food--;
		data->map[data->pos_player_x - 1][data->pos_player_y] = 'P';
		data->map[data->pos_player_x][data->pos_player_y] = '0';
		data->pos_player_x--;
		ft_putnbr_fd(data->num_movements, 1);
		ft_putchar_fd('\n', 1);
		print_map(data, 32);
	}
}

static void	move_down(t_data *data)
{
	if ((data->map[data->pos_player_x + 1][data->pos_player_y] != '1')
		&& !check_exit(data,
		data->map[data->pos_player_x + 1][data->pos_player_y]))
	{
		data->num_movements++;
		if (data->map[data->pos_player_x + 1][data->pos_player_y] == 'C')
			data->num_food--;
		data->map[data->pos_player_x + 1][data->pos_player_y] = 'P';
		data->map[data->pos_player_x][data->pos_player_y] = '0';
		data->pos_player_x++;
		ft_putnbr_fd(data->num_movements, 1);
		ft_putchar_fd('\n', 1);
		print_map(data, 32);
	}
}

void	press_key(mlx_key_data_t keydata, void *game_data)
{
	t_data	*data;

	data = game_data;
	(void)keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		free_all(data);
		exit(EXIT_SUCCESS);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
}
