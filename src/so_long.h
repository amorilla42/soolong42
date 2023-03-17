/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:49:01 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 19:27:41 by amorilla         ###   ########.fr       */
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
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*fence;
	mlx_image_t	*food;
	mlx_image_t	*exit;
	char		**map;
	char		**copy_map;
	int			posx_cpy;
	int			posy_cpy;
	int			pos_player_x;
	int			pos_player_y;
	int			num_food;
	int			num_players;
	int			num_exit;
	int			map_height;
	int			map_width;
	int			num_movements;
}				t_data;

int		is_valid_map(t_data *data);
int		print_error(char *str_error);
int		map_inner_check(t_data *data);
void	load_sprites(t_data *data);
void	free_img(t_data *data);
void	print_map(t_data *data, int size);
void	free_map_and_data_fd(t_data *data, int fd);
void	free_map_and_data(t_data *data, char *str);
void	free_all(t_data *data);
void	press_key(mlx_key_data_t keydata, void *game_data);
int		check_exit(t_data *data, char next_pos);
void	free_copymap(t_data *data);
int		map_path_check(t_data *data);
void	free_data(t_data *data, char *msg);
void	print_error_and_exit(char *str_error);
int		free_moves(int *movs, int val);
int		free_copy_error(t_data *data);

#endif