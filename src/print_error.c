/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:21:57 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/17 19:32:43 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str_error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str_error, 2);
	return (0);
}

void	print_error_and_exit(char *str_error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str_error, 2);
	exit(EXIT_FAILURE);
}

int	free_moves(int *movs, int val)
{
	free(movs);
	return (val);
}

int	free_copy_error(t_data *data)
{
	free_copymap(data);
	return (0);
}
