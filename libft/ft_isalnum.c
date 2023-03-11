/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:48:44 by amorilla          #+#    #+#             */
/*   Updated: 2022/04/20 15:00:24 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_isalnum(int a)
{
	return (ft_isalpha(a) || ft_isdigit(a));
}
/*
int main(){
	
	if(ft_isalnum('w'))
		write(1,"1",1);
	return 0;
}
*/
