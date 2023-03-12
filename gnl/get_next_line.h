/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:36:27 by amorilla          #+#    #+#             */
/*   Updated: 2023/03/12 18:58:55 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_gnlsubstr(char *s, unsigned int start, size_t len);
char	*ft_gnlstrdup(char *s1);
void	ft_gnlstrjoin(char **s1, char *s2, size_t s2_len);
void	*ft_gnlcalloc(size_t count, size_t size);
size_t	ft_gnlstrlen(char *s);
char	*get_next_line(int fd);
#endif
