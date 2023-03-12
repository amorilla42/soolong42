/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:18:35 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 21:03:43 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_data *data)
{
	mlx_texture_t	*spriteaux;

	spriteaux = mlx_load_png("./assets/textures/fence.png");
	data->fence = mlx_texture_to_image(data->mlx, spriteaux);
	mlx_delete_texture(spriteaux);
	spriteaux = mlx_load_png("./assets/textures/floor.png");
	data->floor = mlx_texture_to_image(data->mlx, spriteaux);
	mlx_delete_texture(spriteaux);
	spriteaux = mlx_load_png("./assets/textures/food.png");
	data->food = mlx_texture_to_image(data->mlx, spriteaux);
	mlx_delete_texture(spriteaux);
	spriteaux = mlx_load_png("./assets/textures/exit.png");
	data->exit = mlx_texture_to_image(data->mlx, spriteaux);
	mlx_delete_texture(spriteaux);
	spriteaux = mlx_load_png("./assets/textures/player.png");
	data->player = mlx_texture_to_image(data->mlx, spriteaux);
	mlx_delete_texture(spriteaux);
}

void	free_img(t_data *data)
{
	mlx_delete_image(data->mlx, data->fence);
	mlx_delete_image(data->mlx, data->floor);
	mlx_delete_image(data->mlx, data->exit);
	mlx_delete_image(data->mlx, data->food);
	mlx_delete_image(data->mlx, data->player);
}
