/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:49:06 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 19:23:52 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_extension(char *filename)
{
	size_t	len;

	len = (int)ft_strlen(filename);
	return ((len > 4) && (filename[len - 4] == '.')
		&& (filename[len - 3] == 'b')
		&& (filename[len - 2] == 'e')
		&& (filename[len - 1] == 'r'));
}

static void	allocate_map(t_data *data, char *filename)
{
	int		fd;
	int		size;
	char	*gnl;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_data(data, "Cannot open file");
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		size++;
		gnl = get_next_line(fd);
	}
	data->map_height = size;
	data->map = ft_calloc(size + 1, sizeof(char *));
	close(fd);
	if (!data->map)
		free_data(data, "Cannot allocate memory");
}

static void	insert_data_to_map(t_data *data, char *filename)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error("Cannot open file");
		free(data);
		exit(EXIT_FAILURE);
	}
	while (i < data->map_height)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break ;
		i++;
	}
	if (i != data->map_height)
		free_map_and_data_fd(data, fd);
	close(fd);
}

static void	load_map(t_data *data, char *filename)
{
	if (check_file_extension(filename))
	{
		allocate_map(data, filename);
		insert_data_to_map(data, filename);
	}
	else
	{
		print_error("Invalid extension");
		free(data);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **args)
{
	t_data	*game_data;

	if (argc != 2)
		print_error_and_exit("Invalid number of arguments");
	game_data = ft_calloc(1, sizeof(t_data));
	if (!game_data)
		print_error_and_exit("Cannot allocate memory");
	load_map(game_data, args[1]);
	if (is_valid_map(game_data))
	{
		game_data->mlx = mlx_init(32 * game_data->map_width,
				32 * game_data->map_height, "so_long", true);
		if (!game_data->mlx)
			free_map_and_data(game_data, "Cannot allocate memory");
		load_sprites(game_data);
		print_map(game_data, 32);
		mlx_key_hook(game_data->mlx, &press_key, game_data);
		mlx_loop(game_data->mlx);
		free_all(game_data);
	}
	free_map_and_data(game_data, "Map is not valid");
	return (0);
}
