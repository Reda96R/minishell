/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/08/11 20:09:01 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_numeriq(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!_isdigit(str[i]))
		{
			ft_builtins_error(5, str);
			exit(255);
		}
		i++;
	}
	return (1);
}

void	ft_exit(t_cmds *cmd)
{
	int	i;

	i = 1;
	printf("");
	if (!cmd->str[1])
		exit(0);
	if (!check_numeriq(cmd->str[i++]))
		return ;
	if (cmd->str[2])
	{
		ft_builtins_error(6, NULL);
		g_var.exit_status = 1;
		return ;
	}
	i = 0;
	if (!cmd->str[1][i])
	{
		ft_builtins_error(5, cmd->str[i]);
		g_var.exit_status = 255;
	}
	else
	{
		printf("exit\n");
		g_var.exit_status = _atoi(cmd->str[1]);
		exit(g_var.exit_status);
	}
}
