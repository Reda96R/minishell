/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YOUNES <YOUNES@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/31 17:18:03 by YOUNES           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_for_n(char *str, int *n)
{
	int i;
	
	i = 0;
	if (str[i] != '-')
		return (0);
	if (str[i] == '-' && !str[i + 1])
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	*n = 0;
	return (1);
}

void	ft_echo(t_cmds *init)
{
	int i;
	int	n;

	i = 1;
	n = 1;
	if (!init->str[i])
	{
		_dprintf(init->fd_out, "\n");
		return ;
	}
	while (init->str[i])
	{
		if (!check_for_n(init->str[i], &n))
			break ;
		i++;
	}
	while (init->str[i])
	{
		if (!init->str[i + 1])
			_dprintf(init->fd_out, "%s", init->str[i++]);
		else
			_dprintf(init->fd_out, "%s ", init->str[i++]);
	}
	if (n)
		_dprintf(init->fd_out, "\n");
}
