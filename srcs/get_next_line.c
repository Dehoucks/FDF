/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:40:31 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/07 23:13:33 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_newstrjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_removeline(char *stocker)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (stocker[i] != '\n' && stocker[i])
		i++;
	if (!stocker[i])
	{
		free(stocker);
		return (NULL);
	}	
	temp = malloc(sizeof(char) * (ft_strlen(stocker) - i) + 1);
	if (!temp)
		return (NULL);
	i++;
	while (stocker[i])
		temp[j++] = stocker[i++];
	temp[j] = 0;
	free(stocker);
	return (temp);
}

char	*ft_getline(char *source, char *line)
{
	int	i;

	if (!source[0])
		return (NULL);
	i = 0;
	while (source[i] != '\n' && source[i])
		i++;
	i++;
	line = malloc (sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (source[i] != '\n' && source[i])
	{
		line[i] = source[i];
		i++;
	}
	line[i] = source[i];
	i++;
	line[i] = 0;
	return (line);
}

char	*addingbufftostock(char *stocker, int fd)
{
	char	*buffer;
	int		bytesread;

	bytesread = 1;
	while (!ft_strchr(stocker, '\n') && bytesread != 0)
	{
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytesread] = 0;
		stocker = ft_newstrjoin(stocker, buffer);
		free(buffer);
	}
	return (stocker);
}

char	*get_next_line(const int fd)
{
	static char	*stocker;
	char		*myline;

	myline = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stocker = addingbufftostock(stocker, fd);
	if (!stocker)
		return (NULL);
	myline = ft_getline(stocker, myline);
	stocker = ft_removeline(stocker);
	return (myline);
}
