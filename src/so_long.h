/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:49:01 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 16:27:03 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_data
{
	mlx_t	*mlx;
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*fence;
	mlx_image_t	*food;
	mlx_image_t	*exit;
	char		**map;
	int			pos_player_x;
	int			pos_player_y;
	int			num_food;
	int			num_players;
	int			num_exit;
	int			map_height;
	int			map_width;
	int			num_movements;
} t_data;

int		is_valid_map(t_data *data);
int		print_error(char *str_error);
int		map_inner_check(t_data *data);
void	load_sprites(t_data *data);
void	free_img(t_data *data);

#endif