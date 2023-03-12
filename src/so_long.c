/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:49:06 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 17:49:21 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **args)
{
	t_data	*game_data;

	if (argc != 2)
	{
		print_error("Invalid number of arguments");
		exit(EXIT_FAILURE);
	}
	game_data = ft_calloc(1, sizeof(t_data));
	if (!game_data)
	{
		print_error("Cannot allocate memory");
		exit(EXIT_FAILURE);
	}
	//meter mapa en el game_data->map, anchura y altura y calcular pos de playerx e y
	//comprobar si el mapa es valido
	game_data->mlx = mlx_init(32 * game_data->map_width,
	32 * game_data->map_height, "so_long", true);
	if (!game_data->mlx)
	{
		print_error("Cannot allocate memory");
		//free el  mapa y despues game_data
		exit(EXIT_FAILURE);
	}
	load_sprites(game_data);
	print_map(game_data, 32);
	mlx_key_hook(game_data->mlx, &press_key, game_data);
	mlx_loop(game_data->mlx);
	//freeall function
	return (0);
}