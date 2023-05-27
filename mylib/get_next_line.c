/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:55:19 by rerayyad          #+#    #+#             */
/*   Updated: 2023/04/25 16:45:24 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_search(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_line(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_saver(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (0);
	}
	str = (char *)malloc(sizeof (char) * ft_strlen(stock) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_fill(char *stock, int fd)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 1;
	while (i && !ft_search(stock, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free (str);
			free(stock);
			return (NULL);
		}
		str[i] = '\0';
		stock = ft_strjoin(stock, str);
	}
	free(str);
	return (stock);
}

int	get_next_line(int fd, char **line)
{
	char		*str;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_fill(stock, fd);
	if (!stock)
		return (0);
	str = ft_line(stock);
	stock = ft_saver(stock);
	if (!str[0])
	{
		free(str);
		free (stock);
		return (0);
	}
	*line = str;
  return (1);
}
