/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _atoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:51:10 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/16 12:22:49 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	_atoi(const char *str)
{
	int					i;
	int					si;
	unsigned long long	res;

	i = 0;
	res = 0;
	si = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			si *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res > LONG_MAX)
			return (ft_builtins_error(7, (char *)str), 2);
		i++;
	}
	return ((int)res * si);
}
