/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/29 15:01:21 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_numeriq(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("exit\n<?>: exit: %s: numeric argument required\n", str);
			g_var.exit_status = 255;
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_exit(t_cmds *cmd)
{
	int				i;
	unsigned char	exit_code;
	
	i = 1;
	if (!cmd->str[1])
		exit(0);
	if (!cmd->str[1][i])
	{
		printf("exit\n<?>: exit: %s: numeric argument required\n", cmd->str[i]);
		g_var.exit_status = 255;
	}
	while (cmd->str[i])
		if (!check_numeriq(cmd->str[i++]))
			break ;
	if (cmd->str[2])
	{
		printf("exit\n<?>: exit: too many arguments\n");
		return ;
	}
	exit_code = _atoi(cmd->str[1]);
	exit(g_var.exit_status);
}
