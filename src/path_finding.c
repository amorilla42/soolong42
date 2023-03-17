/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:49:12 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 17:41:52 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	copymap(t_data *data)
{
	int	i;

	i = 0;
	data->posx_cpy = data->pos_player_x;
	data->posy_cpy = data->pos_player_y;
	data->copy_map = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->copy_map)
		free_map_and_data(data, "Cannot allocate memory");
	while (i < data->map_height)
	{
		data->copy_map[i] = ft_strdup(data->map[i]);
		i++;
	}
}
//up x y, down x y, right x y, left x y
static int	*get_moves(t_data *data)
{
	int *moves;

	moves = ft_calloc(8, sizeof(int));
	if (!moves)
	{
		free_copymap(data);
		free_all(data);
	}
	moves[0] = data->posx_cpy - 1;
	moves[1] = data->posy_cpy;
	moves[2] = data->posx_cpy + 1;
	moves[3] = data->posy_cpy;
	moves[4] = data->posx_cpy;
	moves[5] = data->posy_cpy + 1;
	moves[6] = data->posx_cpy;
	moves[7] = data->posy_cpy - 1;
	return (moves);
}

static int check_legal_move(t_data *data, int mov_x, int mov_y, char elem)
{
	if (mov_x < 0 || mov_y < 0 || mov_x >= data->map_height
		|| mov_y >= data->map_width)
		return (0);
	return ((data->copy_map[mov_x][mov_y] != '1')
			&& (elem == 'E'
			|| (elem == 'C' && data->copy_map[mov_x][mov_y] != 'E')));
}

static int	pathfind(t_data *data, int x, int y, char elem)
{
	int	*moves;
	int	i;

	moves = get_moves(data);
	i = 0;
	if (data->posx_cpy == x && data->posy_cpy == y)
	{
		free(moves);
		return (1);
	}
	while (i < 8)
	{
		if (check_legal_move(data, moves[i], moves[i + 1], elem))
		{
			data->copy_map[data->posx_cpy][data->posy_cpy] = '1';
			data->posx_cpy = moves[i];
			data->posy_cpy = moves[i + 1];
			if (pathfind(data, x, y, elem))
			{
				free(moves);
				return (1);
			}
		}
		i += 2;
	}
	free(moves);
	return (0);
}

static int	free_copy_error(t_data *data)
{
	free_copymap(data);
	return (print_error("Worm or exit not reachable"));
}


int	map_path_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			{
				copymap(data);
				if (!pathfind(data, i, j, data->copy_map[i][j]))
					return (free_copy_error(data));
				free_copymap(data);
			}
			j++;
		}
		i++;
	}
	return (1);
}
