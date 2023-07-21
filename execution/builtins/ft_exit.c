/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:40:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/07/21 09:24:09 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_cmds *cmd)
{
	int				i;
	unsigned char	exit_code;
	
	i = 0;
	if (!cmd->str[1])
		exit(0);
	while (cmd->str[1][i])
	{
		i = 0;
		if (!ft_isdigit(cmd->str[1][i]))
		{
			printf("exit\n<?>: exit: %s: numeric argument required\n", cmd->str[i]);
			exit(255);
		}
		i++;
	}
	if (cmd->str[2])
	{
		printf("exit\n<?>: exit: too many arguments\n");
		return ;
	}
	
	exit_code = ft_atoi(cmd->str[1]);
	exit(exit_code);
}
