/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:16:23 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/07 23:14:53 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <sys/stat.h> 
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define BUFFER_SIZE 10
char	*ft_removeline(char *stocker);
char	*get_next_line(const int fd);
char	*ft_getline(char *source, char *line);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);

#endif