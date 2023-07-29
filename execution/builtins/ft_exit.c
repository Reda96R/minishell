/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/28 09:21:26 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_numeriq(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("exit\n<?>: exit: %s: numeric argument required\n", str);
			exit(255);
		}
		i++;
	}
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
		exit(255);
	}
	while (cmd->str[i])
		check_numeriq(cmd->str[i++]);
	if (cmd->str[2])
	{
		printf("exit\n<?>: exit: too many arguments\n");
		return ;
	}
	exit_code = _atoi(cmd->str[1]);
	exit(exit_code);
}
