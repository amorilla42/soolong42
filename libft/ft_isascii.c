/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:07:51 by amorilla          #+#    #+#             */
/*   Updated: 2022/04/20 12:16:16 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int main(){

	if(ft_isascii('7'))
		write(1,"1",1);
	if(ft_isascii('e'))
		write(1,"1",1);

	return 0;
}
*/
