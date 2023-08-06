/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:21:47 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/31 17:13:20 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_putchar(int fd, char c, int *len)
{
	write(fd, &c, 1);
	*len = *len + 1;
}

void	ft_putstr(int fd, char *str, int *len)
{
	int i = 0;
	if(!str)
		str = "(null)";
	while(str[i])
	{
		ft_putchar(fd, str[i], len);
		i++;
	}
}

int _dprintf(int fd, const char *str, ...)
{
	va_list ap;
	int len = 0;
	int i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if(str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 's')
				ft_putstr(fd, va_arg(ap, char *), &len);
		}
		else
			ft_putchar(fd, str[i], &len);
		i++;
	}
	va_end(ap);
	return len;
}