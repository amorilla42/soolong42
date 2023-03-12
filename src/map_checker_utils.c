/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:09:52 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 16:13:48 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	value_is_valid(t_data *data, int i, int j)
{
	
}

int	map_inner_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		while (j < data->map_width)
		{
			if(data->map[i][j] == '1')
			j++;
		}
		i++;
	}
	
	return (1);
}